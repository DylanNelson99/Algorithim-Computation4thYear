//Dylan Nelson - X00144862

#include "HuffmanTree.h"																	

using namespace std;

HuffmanNode::HuffmanNode() = default;

HuffmanNode::HuffmanNode(int data) : data{ data } {  }

ostream& operator<<(
	ostream & outputting, 
	const HuffmanNode & node
	) {
	if (&node != nullptr && node.data != 0)
		outputting << "\t" << node.data;
	outputting << "\n";
	outputting << *(node.leftPtr);
	outputting << *(node.rightPtr);

	return outputting;
}