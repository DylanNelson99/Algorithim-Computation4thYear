#include "TextCompression.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {

	HuffmanTree* huffman_tree;

	ifstream initial_in("initial.txt", ios::binary);																
	ofstream encoded_out("encoded.txt", ios::binary);
	huffman_tree = TextCompression::encode_input_file_to_file(initial_in, encoded_out);								
	initial_in.close();
	encoded_out.close();


	ifstream encoded_in("encoded.txt", ios::binary);
	ofstream decoded_out("decoded.txt", ios::binary);
	TextCompression::decode_input_file_to_file(encoded_in, decoded_out, huffman_tree);								
	encoded_in.close();
	decoded_out.close();



	initial_in.open("initial.txt", ios::binary);
	ofstream compressed_out("compressed.txt", ios::binary);
	huffman_tree = nullptr;
	huffman_tree = TextCompression::compress_input_file(initial_in, compressed_out);								
	initial_in.close();
	compressed_out.close();



	ifstream compressed_in("compressed.txt", ios::binary);
	ofstream decompressed_out("decompressed.txt", ios::binary);
	TextCompression::decompress_input_file(compressed_in, decompressed_out, huffman_tree);							
	compressed_in.close();
	decompressed_out.close();



	initial_in.open("initial.txt", ios::binary);
	ofstream independent_compressed_out("independent-compressed.txt", ios::binary);
	TextCompression::compress_input_file_independent(initial_in, independent_compressed_out);						
	initial_in.close();
	independent_compressed_out.close();


	ifstream independent_compressed_in("independent-compressed.txt", ios::binary);
	ofstream independent_decompressed_out("independent-decompressed.txt", ios::binary);
	TextCompression::decompress_input_file_independent(independent_compressed_in, independent_decompressed_out);	
	independent_compressed_in.close();
	independent_decompressed_out.close();