//Dylan Nelson - X00144862
#include "HuffmanTree.h"
#pragma once

#include <iostream>

using namespace std;

//Declare Class
class HuffmanTree;	

class HuffmanNode
{
private:
	//Adding data members
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
