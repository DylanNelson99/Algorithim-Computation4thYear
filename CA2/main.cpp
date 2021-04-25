#include "TextCompression.h"
#include <fstream>
#include <iostream>

using namespace std;

	/*
	Title : using fstream to read every character including spaces and newline
	Author : Toby Speight
	Availability : https://stackoverflow.com/questions/116951/using-fstream-to-read-every-character-including-spaces-and-newline/117015#117015
	*/

int main() {

	HuffmanTree* huffman_tree;


	//Encode text to 1's and 0's
	ifstream start_in("Start.txt", ios::binary);
	ofstream encode_out("Encode.txt", ios::binary);
	huffman_tree = TextCompression::encode_input_to_file(start_in, encode_out);
	start_in.close();
	encode_out.close();

	//Decode back to normal text
	ifstream encode_in("Encode.txt", ios::binary);
	ofstream decode_out("Decode.txt", ios::binary);
	TextCompression::decode_input_to_file(encode_in, decode_out, huffman_tree);
	encode_in.close();
	decode_out.close();


	//Compress file
	start_in.open("Start.txt", ios::binary);
	ofstream compress_out("Compress.txt", ios::binary);
	huffman_tree = nullptr;
	huffman_tree = TextCompression::compress_input(start_in, compress_out);
	start_in.close();
	compress_out.close();


	//Decompress using Huffman Tree
	ifstream compress_in("Compress.txt", ios::binary);
	ofstream decompress_out("Decompress.txt", ios::binary);
	TextCompression::decompress_input_file(compress_in, decompress_out, huffman_tree);
	compress_in.close();
	decompress_out.close();

}