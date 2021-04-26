//Dylan Nelson - X00144862

#include "HuffmanTree.h"
#include "HuffmanNode.h"
using namespace std;

HuffmanTree::HuffmanTree() = default;

HuffmanTree::HuffmanTree(int data_in, int size_in) :
	size{ size_in },
	root{ new HuffmanNode(data_in) } {  }

HuffmanTree::HuffmanTree(HuffmanTree * l_tree, HuffmanTree * r_node, int total_size) :
	size{ total_size },
	root{ new HuffmanNode() } {

	root->left = l_tree;
	root->right = r_node;
}

//Comparing HuffmanTree
bool CompareHuffmanTree::operator() (const HuffmanTree * left, const HuffmanTree * right) const
{
	return left->size > right->size;
}

string HuffmanTree::get_Path(int find)
{
	return get_Path(find, root, "");
}

string HuffmanTree::get_Path(int find, HuffmanNode * node, string path)
{
	if (node == nullptr || node->data == find)
		return path;

	if (node->left != nullptr) {
		path.push_back('0');																
		string returned_path = get_Path(find, node->left->root, path);
		if (returned_path != "")
			return returned_path;

		path.pop_back();	//back to end of queue																
	}

	if (node->right != nullptr) {
		path.push_back('1');																
		string returned_path = get_Path(find, node->right->root, path);
		if (returned_path != "")
			return returned_path;
	}

	return "";	//empty string																			
}

ostream& operator<<(ostream & out, const HuffmanTree & tree) {
	if (&tree != nullptr && tree.root != nullptr) {
		out << tree.size;
		out << *tree.root;
	}

	return out;
}

