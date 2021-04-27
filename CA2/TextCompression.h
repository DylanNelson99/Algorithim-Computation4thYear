//Dylan Nelson - X00144862

#pragma once

#include "HuffmanTree.h"
#include <fstream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class TextCompression
{
private:
	TextCompression();

	/*
	Title: Read whole ASCII file into C++ std::string
	Author: Jerry Coffin [StackOverflow]
	Link: https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring/2602258#2602258
	*/

	static const int PSEUDO_EOF = 128;

	//Encode
	static string encodeText(
		const string& inputs, HuffmanTree*& huffman_tree_out
	);

	static string encode_char_map(
		const string& inputs, const map<int, string>& char_encoding
	);
	
	//Mapping
	static map<int, string> get_map(
		HuffmanTree* tree, 
		map<int, 
		int> frequency
	);

	static HuffmanTree* get_tree_map(
		map<int, int> frequency
	);

	static priority_queue<HuffmanTree*, 
		vector<HuffmanTree*>, 
		CompareHuffmanTree> get_priority_queue_from_map(
			map<int, 
			int> frequency
		);

	static void char_frequency(
		const string& inputs, map<int, 
		int>& frequency
	);

	//Decode
	static string decode_text(
		const string& inputs, 
		const HuffmanTree* tree
	);

	static void get_string(
		ifstream& file_in, 
		string& outputting
	);

	//Compression
	static void get_compressed(
		string& encode_string,
		string& compress_string_out
	);

	static void pop_string_with_zeros(
		string& to_pop
	);

	static void get_binary_string(
		const string& encode_string, 
		string& binary_string_out
	);

	//Encode HuffmanTree

	/*
	Title: Huffman Coding
	Author: Purdue University
	Link: https://engineering.purdue.edu/ece264/17au/hw/HW13?alt=huffman
	*/

	static string encode_tree(
		HuffmanTree* tree
	);

	static string encode_help(HuffmanTree* tree,
		string& string
	);

	//Decode HuffmanTree
	/*
	Same link used for decode as encode
	*/
	static HuffmanTree* decode_tree(
		const string& binary_string,
		const unsigned int binary_bits
	);

public:
	//Encode
	static string encode_text(
		const string& inputs,
		ofstream& file_out,
		HuffmanTree*& huffman_tree_out
	);			

	static HuffmanTree* encode_input(
		ifstream& file_in,
		ofstream& file_out
	);

	//Decode
	static string decode_input(
		const string& inputs,
		ofstream& file_out,
		const HuffmanTree* tree
	);			

	static void decode_inputFile(
		ifstream& file_in,
		ofstream& file_out,
		const HuffmanTree* tree
	);

	//Compress HuffmanTree
	static HuffmanTree* compress_input(
		ifstream& file_in,
		ofstream& file_out
	);

	static void decompress_inputFile(
		ifstream& file_in,
		ofstream& file_out,
		const HuffmanTree* tree
	);
};
