#pragma once

#include <iostream>

using namespace std;

class HuffmanTree;	

class HuffmanNode
{
private:
	int data = 0;
	HuffmanTree* left = nullptr;
	HuffmanTree* right = nullptr;
	friend class HuffmanTree;
	friend class TextCompression;
	friend ostream& operator<<(ostream& out, const HuffmanNode& node);

public:
	HuffmanNode();
	HuffmanNode(int data_in);
};
