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

class HuffmanTree
{
public:
	HuffmanTree();
	HuffmanTree(int data_in, int weight_in);
	HuffmanTree(HuffmanTree* left_tree, HuffmanTree* right_node, int total_weight);

private:
	HuffmanNode* root;
	int weight = -1;																		

	string get_Path(int to_find);
	string get_Path(int to_find, HuffmanNode* tree, string path);

	friend class TextCompression;
	friend class CompareHuffmanTree;
	friend ostream& operator<<(ostream& out, const HuffmanTree& tree);
};

class CompareHuffmanTree
{
public:
	bool operator() (const HuffmanTree* lhs, const HuffmanTree* rhs) const;
};
