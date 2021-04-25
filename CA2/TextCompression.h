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

	static const int PSEUDO_EOF = 256;

	//Encode
	static string encodeText(const string& input, HuffmanTree*& huffman_tree_out);
	static string encode_char_map(const string& input, const map<int, string>& char_encoding);
	
	//Mapping
	static map<int, string> get_mapping_from_tree(HuffmanTree* huffman_tree, map<int, int> char_frequency);
	static HuffmanTree* get_huffman_tree_from_map(map<int, int> char_frequency);
	static priority_queue<HuffmanTree*, vector<HuffmanTree*>, CompareHuffmanTree> get_priority_queue_from_map(map<int, int> char_frequency);
	static void populate_char_frequency(const string& input, map<int, int>& char_frequency);

	//Decode
	static string decode_text(const string& input, const HuffmanTree* huffman_tree);

	static void get_string_from_file(ifstream& in_file, string& out);

	//Compression
	static void get_compressed_string(string& encoded_string, string& compressed_string_out);
	static void pad_string_with_zeros(string& to_pad);

	static void get_binary_string(const string& encoded_string, string& binary_string_out);

	//Encode HuffmanTree

	/*
	Title: Huffman Coding
	Author: Purdue University
	Link: https://engineering.purdue.edu/ece264/17au/hw/HW13?alt=huffman
	*/

	static string encode_huffman_tree(HuffmanTree* huffman_tree);
	static string encode_huffman_tree_helper(HuffmanTree* huffman_tree, string& accumulated_string);

	//Decode HuffmanTree
	/*
	Same link used for decode as encode
	*/
	static HuffmanTree* decode_huffman_tree(const string& binary_string, const unsigned int bits_used_for_tree);

public:
	//Encode
	static string encode_input_text(const string& input, ofstream& out_file, HuffmanTree*& huffman_tree_out);					
	static HuffmanTree* encode_input_to_file(ifstream& in_file, ofstream& out_file);

	//Decode
	static string decode_input_text(const string& input, ofstream& out_file, const HuffmanTree* huffman_tree);					
	static void decode_input_to_file(ifstream& in_file, ofstream& out_file, const HuffmanTree* huffman_tree);

	//Compress HuffmanTree
	static HuffmanTree* compress_input(ifstream& in_file, ofstream& out_file);
	static void decompress_input_file(ifstream& in_file, ofstream& out_file, const HuffmanTree* huffman_tree);
};
