#include "TextCompression.h"
#include <sstream>
#include <bitset>
#include <stack>
#include <streambuf>

using namespace std;

// All Public functions

string TextCompression::encode_input_text(const string& input, ofstream& out_file, HuffmanTree*& huffman_tree_out) {
	string encoded_string = encodeText(input, huffman_tree_out);
	out_file << encoded_string;

	return encoded_string;
}

HuffmanTree* TextCompression::encode_input_to_file(ifstream& in_file, ofstream& out_file) {
	HuffmanTree* huffman_tree;
	string input_text;
	get_string_from_file(in_file, input_text);

	string encoded_string = encode_input_text(input_text, out_file, huffman_tree);

	return huffman_tree;
}


string TextCompression::decode_input_text(const string& input, ofstream& out_file, const HuffmanTree* huffman_tree) {
	string decoded_string = decode_text(input, huffman_tree);
	out_file << decoded_string;

	return decoded_string;
}

void TextCompression::decode_input_to_file(ifstream& in_file, ofstream& out_file, const HuffmanTree* huffman_tree) {
	string input_text;
	get_string_from_file(in_file, input_text);

	decode_input_text(input_text, out_file, huffman_tree);
}


HuffmanTree* TextCompression::compress_input(ifstream& in_file, ofstream& out_file) {
	HuffmanTree* huffman_tree_out;
	string input_text;
	//read in file
	get_string_from_file(in_file, input_text);

	string encoded_string = encodeText(input_text, huffman_tree_out);

	//Compress String
	string compressed_string_out;
	get_compressed_string(encoded_string, compressed_string_out);

	out_file << compressed_string_out;

	return huffman_tree_out;
}

void TextCompression::decompress_input_file(ifstream& in_file, ofstream& out_file, const HuffmanTree* huffman_tree) {
	string input_text;
	//Look at compressed string
	get_string_from_file(in_file, input_text);

	//Make string into binary
	string binary_string_out;
	get_binary_string(input_text, binary_string_out);

	//Use decode method to cahnge from binary to orignal text
	decode_input_text(binary_string_out, out_file, huffman_tree);
}


TextCompression::TextCompression() = default;

//All Private functions

string TextCompression::encodeText(const string & input, HuffmanTree * &huffman_tree_out) {
	if (input.length() < 2)									
		return input;

	map<int, int> char_frequency;
	populate_char_frequency(input, char_frequency);

	huffman_tree_out = get_huffman_tree_from_map(char_frequency);

	map<int, string> char_encoding = get_mapping_from_tree(huffman_tree_out, char_frequency);		
	string encoded_string = encode_char_map(input, char_encoding);

	return encoded_string;
}

//Encode caharacters in the map
string TextCompression::encode_char_map(const string & input, const map<int, string>&char_encoding) {
	string encoded_string = "";
	for (int input_char : input) {
		encoded_string.append(char_encoding.at(input_char));
	}
	//.append Pseudo_eof at the end of string
	encoded_string.append(char_encoding.at(PSEUDO_EOF));		
	return encoded_string;
}

map<int, string> TextCompression::get_mapping_from_tree(HuffmanTree * huffman_tree, map<int, int> char_frequency) {
	map<int, string> char_path;

	for (pair<int, int> char_pair : char_frequency) {
		string path_to_char = huffman_tree->get_Path(char_pair.first);

		char_path.insert(pair<int, string>(char_pair.first, path_to_char));
	}

	return char_path;
}

HuffmanTree* TextCompression::get_huffman_tree_from_map(map<int, int> char_frequency)
{
	auto tree_queue = get_priority_queue_from_map(char_frequency);						

	while (tree_queue.size() > 1) {									
		HuffmanTree* first_pop = tree_queue.top();
		tree_queue.pop();

		HuffmanTree* second_pop = tree_queue.top();
		tree_queue.pop();

		tree_queue.push(new HuffmanTree(first_pop, second_pop, first_pop->weight + second_pop->weight));
	}

	return tree_queue.top();
}

priority_queue<HuffmanTree*, vector<HuffmanTree*>, CompareHuffmanTree>
TextCompression::get_priority_queue_from_map(map<int, int> char_frequency) {
	priority_queue<HuffmanTree*, vector<HuffmanTree*>, CompareHuffmanTree> tree_queue;

	//move map data to a priority queue
	map<int, int>::iterator it = char_frequency.begin();															
	while (it != char_frequency.end()) {
		tree_queue.push(new HuffmanTree(it->first, it->second));
		++it;
	}

	return tree_queue;
}

//Populating the frequency of the characters
void TextCompression::populate_char_frequency(const string & input, map<int, int>&char_frequency) {
	char_frequency.insert(pair<int, int>(PSEUDO_EOF, 1));																
	for (char current_char : input) {
		if (char_frequency.find(current_char) == char_frequency.end())
			char_frequency.insert(pair<int, int>(current_char, 1));
		else
			char_frequency[current_char]++;
	}
}

string TextCompression::decode_text(const string & input, const HuffmanTree * huffman_tree) {
	string decoded_string = "";
	string traversed = "";
	HuffmanTree traversal_copy = *huffman_tree;
	for (size_t i = 0; i <= input.size(); ++i) {
		if (traversal_copy.root->data == PSEUDO_EOF)
			break;
		//Path then resets to 0
		if (traversal_copy.root->data != 0) {																			
			decoded_string.push_back((char)traversal_copy.root->data);
			traversal_copy = *huffman_tree;
			--i;																										
		}
		//Needed to decode the final character in the text
		else if (i != input.size()) {
			if (input[i] == '0') {
				traversed += '0';
				traversal_copy = *(traversal_copy.root->left);
			}
			else {
				traversed += '1';
				traversal_copy = *(traversal_copy.root->right);
			}
		}
	}

	return decoded_string;
}

/*
	Title: Read whole ASCII file into C++ std::string
	Author: Jerry Coffin [StackOverflow]
	Link: https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring/2602258#2602258
*/
void TextCompression::get_string_from_file(ifstream & in_file, string & out)
{
	ostringstream buffer;
	buffer << in_file.rdbuf();																							
	out.assign(buffer.str());
}


/*
	Title: Convert a string of binary into an ASCII string
	Author: Wilson
	Availability: https://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c/23344876#23344876
*/
void TextCompression::get_compressed_string(string & encoded_string, string & compressed_string_out) {
	pad_string_with_zeros(encoded_string);



	compressed_string_out = "";
	istringstream encoded_stream(encoded_string);
	string output;
	while (encoded_stream.good())
	{
		bitset<8> bit_set;
		encoded_stream >> bit_set;																						
		char bits_as_char = char(bit_set.to_ulong());																	
		compressed_string_out.push_back(bits_as_char);
	}
}

void TextCompression::pad_string_with_zeros(string & to_pad) {
	int number_bits = to_pad.size();
	int number_bits_required = number_bits + 8 - (number_bits % 8);
	int num_pads = number_bits_required - number_bits;

	for (int i = 0; i < num_pads; i++) {
		to_pad.push_back('0');
	}
}


/*
		Title: Converting chars to binary in C++
		Author:unkown
		Availability: https://stackoverflow.com/questions/32538895/converting-chars-to-binary-in-c/32538948#32538948
*/
void TextCompression::get_binary_string(const string & encoded_string, string & binary_string_out) {
	binary_string_out = "";
	for (char encoded_char : encoded_string) {

		binary_string_out.append(bitset<8>(encoded_char).to_string());
	}
}


/*
Title: Huffman Coding
Used: Encode and Decode
Author: Purdue University
Link: https://engineering.purdue.edu/ece264/17au/hw/HW13?alt=huffman
*/
string TextCompression::encode_huffman_tree(HuffmanTree * huffman_tree) {

	string encoded_string = "";
	encode_huffman_tree_helper(huffman_tree, encoded_string);
	encoded_string.append("0");
	return encoded_string;
}

string TextCompression::encode_huffman_tree_helper(HuffmanTree * huffman_tree, string & accumulated_string) {
	if (huffman_tree != nullptr) {
		encode_huffman_tree_helper(huffman_tree->root->left, accumulated_string);										
		encode_huffman_tree_helper(huffman_tree->root->right, accumulated_string);
		if (huffman_tree->root->data != 0)
			//Add 1 and the char
			accumulated_string.append("1" + bitset<8>(huffman_tree->root->data).to_string());							
		else
			//Add 0 
			accumulated_string.append("0");																				
	}

	return accumulated_string;
}

HuffmanTree* TextCompression::decode_huffman_tree(const string & encoded_tree, const unsigned int bits_used_for_tree) {

	stack<HuffmanTree*> stack;
	HuffmanTree* huffman_tree = nullptr;
	bool eof_added = false;
	for (unsigned int i = 0; i <= bits_used_for_tree;) {
		unsigned int position = i;
		if (bits_used_for_tree - position > 8) {
			if (encoded_tree[position] == '1') {																		
				bitset<8> char_bit_set;
				stringstream ss_tree_size(encoded_tree.substr(position + 1, 8));										
				ss_tree_size >> char_bit_set;																			
				int to_add = char_bit_set.to_ulong();
				if (eof_added == false && char_bit_set.to_string() == "00000000") {										
					eof_added = true;
					to_add = PSEUDO_EOF;
				}
				stack.push(new HuffmanTree(to_add, 0));																
				i += 9;
				continue;																							
			}
			else if (stack.size() > 1) {																			
				HuffmanTree* first_pop = stack.top();
				stack.pop();

				HuffmanTree* second_pop = stack.top();
				stack.pop();

				stack.push(new HuffmanTree(second_pop, first_pop, 0));
			}
			++i;
		}
		else break;
	}
	if (huffman_tree == nullptr) {																						
		while (stack.size() > 1) {
			HuffmanTree* first_pop = stack.top();
			stack.pop();

			HuffmanTree* second_pop = stack.top();
			stack.pop();

			stack.push(new HuffmanTree(second_pop, first_pop, 0));
		}

		huffman_tree = stack.top();
	}
	return huffman_tree;
}


