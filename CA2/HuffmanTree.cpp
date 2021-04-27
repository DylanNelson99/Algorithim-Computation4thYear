//Dylan Nelson - X00144862

#include "HuffmanTree.h"
#include "HuffmanNode.h"
using namespace std;

HuffmanTree::HuffmanTree() = default;

HuffmanTree::HuffmanTree(
	int data,
	int size_in
) :
	size{ size_in },
	root{ new HuffmanNode(data) } {  }

HuffmanTree::HuffmanTree(
	HuffmanTree * left,
	HuffmanTree * right,
	int total
) :
	size{ total },
	root{ new HuffmanNode() } {

	root->leftPtr = left;
	root->rightPtr = right;
}

//Comparing HuffmanTree
bool CompareHuffmanTree::operator() (
	const HuffmanTree * leftPtr,
	const HuffmanTree * rightPtr
	) 
	const
{
	return leftPtr->size > rightPtr->size;
}

string HuffmanTree::get_Path(
	int find
)
{
	return get_Path(find, root, "");
}

string HuffmanTree::get_Path(
	int find,
	HuffmanNode * node,
	string Path
) {
	if (node == nullptr || node->data == find)
		return Path;

	if (node->leftPtr != nullptr) {
		Path.push_back('0');																
		string returned_path = get_Path(find, node->leftPtr->root, Path);
		if (returned_path != "")
			return returned_path;

		Path.pop_back();	//back to end of queue																
	}

	if (node->rightPtr != nullptr) {
		Path.push_back('1');																
		string returned_path = get_Path(find, node->rightPtr->root, Path);
		if (returned_path != "")
			return returned_path;
	}

	return "";	//empty string																			
}

ostream& operator<<(
	ostream & outputting,
	const HuffmanTree & tree
	) {
	if (&tree != nullptr && tree.root != nullptr) {
		outputting << tree.size;
		outputting << *tree.root;
	}

	return outputting;
}

