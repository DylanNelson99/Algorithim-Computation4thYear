//Dylan Nelson - X00144862

#include "TextCompression.h"
#include <sstream>
#include <bitset>
#include <stack>
#include <streambuf>

using namespace std;

//****************************************************** All Public functions ******************************************************

//Encode
string TextCompression::encode_text(
	const string& inputs,
	ofstream& file_out,
	HuffmanTree*& huffman_tree_out
) {
	string encode_huffman_string = encodeText(inputs, huffman_tree_out);
	file_out << encode_huffman_string;

	return encode_huffman_string;
}

HuffmanTree* TextCompression::encode_input(
	ifstream& file_in,
	ofstream& file_out
) {
	HuffmanTree* tree;
	string input_text;
	get_string(file_in, input_text);
	string encode_huffman_string = encode_text(input_text, file_out, tree);

	return tree;
}

//Decode
string TextCompression::decode_input(
	const string& inputs,
	ofstream& file_out, 
	const HuffmanTree* tree
) {
	string decode_string = decode_text(inputs, tree);
	file_out << decode_string;

	return decode_string;
}

void TextCompression::decode_inputFile(
	ifstream& file_in,
	ofstream& file_out,
	const HuffmanTree* tree
) {
	string input_text;
	get_string(file_in, input_text);
	decode_input(input_text, file_out, tree);
}

//Compress
HuffmanTree* TextCompression::compress_input(
	ifstream& file_in,
	ofstream& file_out
) {
	HuffmanTree* huffman_tree_out;
	string input_text;
	//read in file
	get_string(file_in, input_text);

	string encode_huffman_string = encodeText(input_text, huffman_tree_out);

	//Compress String
	string compress_string_out;
	get_compressed(encode_huffman_string, compress_string_out);

	file_out << compress_string_out;

	return huffman_tree_out;
}

//Decompress
void TextCompression::decompress_inputFile(
	ifstream& file_in,
	ofstream& file_out,
	const HuffmanTree* tree
) {
	string input_text;
	//Look at compressed string
	get_string(file_in, input_text);

	//Make string into binary
	string binary_string_out;
	get_binary_string(input_text, binary_string_out);

	//Use decode method to cahnge from binary to orignal text
	decode_input(binary_string_out, file_out, tree);
}


TextCompression::TextCompression() = default;

//****************************************************** All Private functions ******************************************************
//Encode txt for compression
string TextCompression::encodeText(
	const string & inputs,
	HuffmanTree * &huffman_tree_out
) {
	if (inputs.length() < 2)									
		return inputs;

	map<int, int> frequency;
	char_frequency(inputs, frequency);
	huffman_tree_out = get_tree_map(frequency);
	map<int, string> char_encoding = get_map(huffman_tree_out, frequency);		
	string encode_huffman_string = encode_char_map(inputs, char_encoding);
	return encode_huffman_string;
}

//Encode characters in the map
string TextCompression::encode_char_map(
	const string & inputs,
	const map<int, string>&char_encoding
) {
	string encode_huffman_string = "";
	for (int input_char : inputs) {
		encode_huffman_string.append(char_encoding.at(input_char));
	}
	//.append Pseudo_eof at the end of string
	encode_huffman_string.append(char_encoding.at(PSEUDO_EOF));		
	return encode_huffman_string;
}

map<int, string> TextCompression::get_map(
	HuffmanTree * tree,
	map<int, int> frequency
) {
	map<int, string> char_path;
	for (pair<int, int> char_pair : frequency) {
		string path_to_char = tree->get_Path(char_pair.first);
		char_path.insert(pair<int, string>(char_pair.first, path_to_char));
	}
	return char_path;
}

HuffmanTree* TextCompression::get_tree_map(
	map<int, int> frequency
) {
	auto queue = get_priority_queue_from_map(frequency);						

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
	map<int, int> frequency
) {
	priority_queue<HuffmanTree*,
		vector<HuffmanTree*>, 
		CompareHuffmanTree> queue;

	//move map data to a priority queue
	map<int, int>::iterator it = frequency.begin();															
	while (it != frequency.end()) {
		queue.push(new HuffmanTree(it->first, it->second));
		++it;
	}
	return queue;
}

//Populating the frequency of the characters
void TextCompression::char_frequency(
	const string & inputs,
	map<int, int>&frequency
) {
	frequency.insert(pair<int, int>(PSEUDO_EOF, 1));																
	for (char current_char : inputs) {
		if (frequency.find(current_char) == frequency.end())
			frequency.insert(pair<int, int>(current_char, 1));
		else
			frequency[current_char]++;
	}
}

//Decode txt for compression
string TextCompression::decode_text(
	const string & inputs,
	const HuffmanTree * tree
) {
	string decode_string = "";
	string traversed = "";
	HuffmanTree traversal_copy = *tree;
	for (size_t i = 0; i <= inputs.size(); ++i) {
		if (traversal_copy.root->data == PSEUDO_EOF)
			break;
		//Path then resets to 0
		if (traversal_copy.root->data != 0) {																			
			decode_string.push_back((char)traversal_copy.root->data);
			traversal_copy = *tree;
			--i;																										
		}
		//Needed to decode the final character in the text
		else if (i != inputs.size()) {
			if (inputs[i] == '0') {
				traversed += '0';
				traversal_copy = *(traversal_copy.root->leftPtr);
			}
			else {
				traversed += '1';
				traversal_copy = *(traversal_copy.root->rightPtr);
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
void TextCompression::get_string(
	ifstream & file_in,
	string & outputting
) {
	ostringstream buffer;
	buffer << file_in.rdbuf();																							
	outputting.assign(buffer.str());
}


/*
	Title: Convert a string of binary into an ASCII string
	Author: Wilson
	Link: https://stackoverflow.com/questions/23344257/convert-a-string-of-binary-into-an-ascii-string-c/23344876#23344876
*/
void TextCompression::get_compressed(
	string & encode_huffman_string,
	string & compress_string_out
) {
	pop_string_with_zeros(encode_huffman_string);

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

void TextCompression::pop_string_with_zeros(
	string & to_pop
) {
	int num_bits = to_pop.size();
	int num_bits_required = num_bits + 8 - (num_bits % 8);
	int num_pads = num_bits_required - num_bits;
	for (int i = 0; i < num_pads; i++) {
		to_pop.push_back('0');
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
string TextCompression::encode_tree(
	HuffmanTree * tree
) {
	string encode_huffman_string = "";
	encode_help(tree, encode_huffman_string);
	encode_huffman_string.append("0");
	return encode_huffman_string;
}

string TextCompression::encode_help(
	HuffmanTree * tree,
	string & string
) {
	if (tree != nullptr) {
		encode_help(tree->root->leftPtr, string);										
		encode_help(tree->root->rightPtr, string);
		if (tree->root->data != 0)
			//Add 1 and the char
			string.append("1" + bitset<8>(tree->root->data).to_string());							
		else
			//Add 0 
			string.append("0");																				
	}
	return string;
}

HuffmanTree* TextCompression::decode_tree(
	const string & encoded_tree,
	const unsigned int binary_bits
) {
	stack<HuffmanTree*> stack;
	HuffmanTree* tree = nullptr;
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
	if (tree == nullptr) {																						
		while (stack.size() > 1) {
			HuffmanTree* first_pop = stack.top();
			stack.pop();
			HuffmanTree* second_pop = stack.top();
			stack.pop();
			stack.push(new HuffmanTree(second_pop, first_pop, 0));
		}
		tree = stack.top();
	}
	//Return the tree data
	return tree;
}


