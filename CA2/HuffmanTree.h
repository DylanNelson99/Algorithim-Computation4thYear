//Dylan Nelson - X00144862

#pragma once
#include "HuffmanNode.h"
#include <iostream>
#include <string>

//Alot of help from Geeks for geeks
/*
Title: Huffman Coding
Author: GeeksForGeeks
Link:https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
*/

using namespace std;

class CompareHuffmanTree
{
public:
	bool operator() (const HuffmanTree* left, const HuffmanTree* right) const;
};

class HuffmanTree
{
private:
	HuffmanNode* root;
	int size = -1;
	string get_Path(int find);
	string get_Path(
		int find, 
		HuffmanNode* tree,
		string path
	);

	friend class TextCompression;
	friend class CompareHuffmanTree;
	friend ostream& operator<<(
		ostream& out,
		const HuffmanTree& tree
		);

public:
	HuffmanTree();
	HuffmanTree(
		int data_in,
		int size_in
	);

	HuffmanTree(
		HuffmanTree* l_tree,
		HuffmanTree* r_node,
		int total_size
	);
};


