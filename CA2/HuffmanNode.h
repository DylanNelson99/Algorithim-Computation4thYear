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
	HuffmanTree* leftPtr = nullptr;
	HuffmanTree* rightPtr = nullptr;
	friend class HuffmanTree;
	friend class TextCompression;
	friend ostream& operator<<(
		ostream& outputting,
		const HuffmanNode& node
		);

public:
	HuffmanNode();

	HuffmanNode(
		int data
	);
};
