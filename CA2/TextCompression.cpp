//Dylan Nelson - X00144862

#include "TextCompression.h"
#include <sstream>
#include <bitset>
#include <stack>
#include <streambuf>

using namespace std;

//****************************************************** All Public functions ******************************************************

//Encode
string TextCompression::encode_input_text(
	const string& input,
	ofstream& out_file,
	HuffmanTree*& huffman_tree_out
) {
	string encode_huffman_string = encodeText(input, huffman_tree_out);
	out_file << encode_huffman_string;

	return encode_huffman_string;
}

HuffmanTree* TextCompression::encode_input_to_file(
	ifstream& in_file,
	ofstream& out_file
) {
	HuffmanTree* huffman_tree;
	string input_text;
	get_string_from_file(in_file, input_text);
	string encode_huffman_string = encode_input_text(input_text, out_file, huffman_tree);

	return huffman_tree;
}

//Decode
string TextCompression::decode_input_text(
	const string& input,
	ofstream& out_file, 
	const HuffmanTree* huffman_tree
) {
	string decode_string = decode_text(input, huffman_tree);
	out_file << decode_string;

	return decode_string;
}

void TextCompression::decode_input_to_file(
	ifstream& in_file,
	ofstream& out_file,
	const HuffmanTree* huffman_tree
) {
	string input_text;
	get_string_from_file(in_file, input_text);
	decode_input_text(input_text, out_file, huffman_tree);
}

//Compress
HuffmanTree* TextCompression::compress_input(
	ifstream& in_file,
	ofstream& out_file
) {
	HuffmanTree* huffman_tree_out;
	string input_text;
	//read in file
	get_string_from_file(in_file, input_text);

	string encode_huffman_string = encodeText(input_text, huffman_tree_out);

	//Compress String
	string compress_string_out;
	get_compressed_string(encode_huffman_string, compress_string_out);

	out_file << compress_string_out;

	return huffman_tree_out;
}

//Decompress
void TextCompression::decompress_input_file(
	ifstream& in_file,
	ofstream& out_file,
	const HuffmanTree* huffman_tree
) {
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

//****************************************************** All Private functions ******************************************************
//Encode txt for compression
string TextCompression::encodeText(
	const string & input,
	HuffmanTree * &huffman_tree_out
) {
	if (input.length() < 2)									
		return input;

	map<int, int> char_freq;
	populate_char_frequency(input, char_freq);
	huffman_tree_out = get_huffman_tree_from_map(char_freq);
	map<int, string> char_encoding = get_mapping_from_tree(huffman_tree_out, char_freq);		
	string encode_huffman_string = encode_char_map(input, char_encoding);
	return encode_huffman_string;
}

//Encode characters in the map
string TextCompression::encode_char_map(
	const string & input,
	const map<int, string>&char_encoding
) {
	string encode_huffman_string = "";
	for (int input_char : input) {
		encode_huffman_string.append(char_encoding.at(input_char));
	}
	//.append Pseudo_eof at the end of string
	encode_huffman_string.append(char_encoding.at(PSEUDO_EOF));		
	return encode_huffman_string;
}

map<int, string> TextCompression::get_mapping_from_tree(
	HuffmanTree * huffman_tree,
	map<int, int> char_freq
) {
	map<int, string> char_path;
	for (pair<int, int> char_pair : char_freq) {
		string path_to_char = huffman_tree->get_Path(char_pair.first);
		char_path.insert(pair<int, string>(char_pair.first, path_to_char));
	}
	return char_path;
}

HuffmanTree* TextCompression::get_huffman_tree_from_map(
	map<int, int> char_freq
) {
	auto queue = get_priority_queue_from_map(char_freq);						

	while (queue.size() > 1) {									
		HuffmanTree* first_pop = queue.top();
		queue.pop();

		HuffmanTree* second_pop = queue.top();
		queue.pop();

		queue.push(new HuffmanTree(first_pop, second_pop, first_pop->size + second_pop->size));
	}

	return queue.top();
}

priority_queue<HuffmanTree*, 
	vector<HuffmanTree*>,
	CompareHuffmanTree>
TextCompression::get_priority_queue_from_map(
	map<int, int> char_freq
) {
	priority_queue<HuffmanTree*,
		vector<HuffmanTree*>, 
		CompareHuffmanTree> queue;

	//move map data to a priority queue
	map<int, int>::iterator it = char_freq.begin();															
	while (it != char_freq.end()) {
		queue.push(new HuffmanTree(it->first, it->second));
		++it;
	}
	return queue;
}

//Populating the frequency of the characters
void TextCompression::populate_char_frequency(
	const string & input,
	map<int, int>&char_freq
) {
	char_freq.insert(pair<int, int>(PSEUDO_EOF, 1));																
	for (char current_char : input) {
		if (char_freq.find(current_char) == char_freq.end())
			char_freq.insert(pair<int, int>(current_char, 1));
		else
			char_freq[current_char]++;
	}
}

//Decode txt for compression
string TextCompression::decode_text(
	const string & input,
	const HuffmanTree * huffman_tree
) {
	string decode_string = "";
	string traversed = "";
	HuffmanTree traversal_copy = *huffman_tree;
	for (size_t i = 0; i <= input.size(); ++i) {
		if (traversal_copy.root->data == PSEUDO_EOF)
			break;
		//Path then resets to 0
		if (traversal_copy.root->data != 0) {																			
			decode_string.push_back((char)traversal_copy.root->data);
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

	return decode_string;
}

/*
	Title: Read whole ASCII file into C++ std::string
	Author: Jerry Coffin [StackOverflow]
	Link: https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring/2602258#2602258
*/
void TextCompression::get_string_from_file(
	ifstream & in_file,
	string & out
) {
	ostringstream buffer;
	buffer << in_file.rdbuf();																							
	out.assign(buffer.str());
}


/*
	Title: Convert a string of binary into an ASCII string
	Author: Wilson
	Link: https://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c/23344876#23344876
*/
void TextCompression::get_compressed_string(
	string & encode_huffman_string,
	string & compress_string_out
) {
	pad_string_with_zeros(encode_huffman_string);

	compress_string_out = "";
	istringstream stream(encode_huffman_string);
	string output;
	while (stream.good())
	{
		bitset<8> bit_set;
		stream >> bit_set;																						
		char bits_as_char = char(bit_set.to_ulong());																	
		compress_string_out.push_back(bits_as_char);
	}
}

void TextCompression::pad_string_with_zeros(
	string & to_pad
) {
	int num_bits = to_pad.size();
	int num_bits_required = num_bits + 8 - (num_bits % 8);
	int num_pads = num_bits_required - num_bits;
	for (int i = 0; i < num_pads; i++) {
		to_pad.push_back('0');
	}
}


/*
		Title: Converting chars to binary in C++
		Author:unkown
		Link: https://stackoverflow.com/questions/32538895/converting-chars-to-binary-in-c/32538948#32538948
*/
void TextCompression::get_binary_string(
	const string & encode_huffman_string,
	string & binary_string_out
) {
	binary_string_out = "";
	for (char encoded_char : encode_huffman_string) {
		binary_string_out.append(bitset<8>(encoded_char).to_string());
	}
}


/*
Title: Huffman Coding
Used: Encode and Decode
Author: Purdue University
Link: https://engineering.purdue.edu/ece264/17au/hw/HW13?alt=huffman
*/
string TextCompression::encode_huffmantree(
	HuffmanTree * huffman_tree
) {
	string encode_huffman_string = "";
	encode_huffmantree_helper(huffman_tree, encode_huffman_string);
	encode_huffman_string.append("0");
	return encode_huffman_string;
}

string TextCompression::encode_huffmantree_helper(
	HuffmanTree * huffman_tree,
	string & acc_string
) {
	if (huffman_tree != nullptr) {
		encode_huffmantree_helper(huffman_tree->root->left, acc_string);										
		encode_huffmantree_helper(huffman_tree->root->right, acc_string);
		if (huffman_tree->root->data != 0)
			//Add 1 and the char
			acc_string.append("1" + bitset<8>(huffman_tree->root->data).to_string());							
		else
			//Add 0 
			acc_string.append("0");																				
	}
	return acc_string;
}

HuffmanTree* TextCompression::decode_huffman_tree(
	const string & encoded_tree,
	const unsigned int binary_bits
) {
	stack<HuffmanTree*> stack;
	HuffmanTree* huffman_tree = nullptr;
	bool attached_EOF = false;
	for (unsigned int i = 0; i <= binary_bits;) {
		unsigned int place = i;
		if (binary_bits - place > 8) {
			if (encoded_tree[place] == '1') {																		
				bitset<8> bit_set;
				stringstream tree_size(encoded_tree.substr(place + 1, 8));										
				tree_size >> bit_set;																			
				int to_add = bit_set.to_ulong();
				if (attached_EOF == false && bit_set.to_string() == "00000000") {										
					attached_EOF = true;
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
	//Return the tree data
	return huffman_tree;
}


