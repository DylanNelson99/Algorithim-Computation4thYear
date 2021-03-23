#include "BinarySearchTree.h"
#include "TreeNode.h"
#include <fstream>
#include <iostream>
#include <string>

//Dylan Nelson - X00144862

BinarySearchTree::BinarySearchTree() = default;
BinarySearchTree::~BinarySearchTree() {
	destruct_tree();
}


//Destructor for node to free space
void BinarySearchTree::destruct_tree() {
	destruct_tree(root);
	root = nullptr;
}

void BinarySearchTree::destruct_tree(TreeNode* node) {
	if (node != nullptr) {
		destruct_tree(node->left);
		destruct_tree(node->right);
		delete node;
		node = nullptr;
	}
}

//Add method
void BinarySearchTree::add(int toadd)
{
	if (root == nullptr) {
		root = new TreeNode(toadd);
		return;
	}
	add(toadd, root);
}
void BinarySearchTree::add(int toadd, TreeNode * node)
{
	if (node->data == toadd) return;

	if (toadd < node->data) {
		if (node->left == nullptr) {
			node->left = new TreeNode(toadd);
			return;
		}

		add(toadd, node->left);
	}
	else {
		if (node->right == nullptr) {
			node->right = new TreeNode(toadd);
			return;
		}
		add(toadd, node->right);
	}
}

//read bst file from txt file
/*
* ---Got some help from here ---
Title : Serialize and Deserialize a Binary Tree
Author : GeeksForGeeks
Link : https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/
-----------------------------------------------------------------------------

Also got help from your notes!!

*/
int BinarySearchTree::Serialise(ofstream& OutFile) {
	int result = Serialise(OutFile, root);
	OutFile << "\n";
	OutFile.close();

	return result;
}
int BinarySearchTree::Deserialise(ifstream& InFile) {
	if (InFile.is_open()) {
		std::string line;
		while (getline(InFile, line))
		{
			if (line != "")
				add(stoi(line));
		}
		return 1;
	}
	return -1;
}

int BinarySearchTree::Serialise(ofstream& OutFile, TreeNode* node) {
	if (OutFile.is_open()) {
		if (node == nullptr) return 1;

		OutFile << node->data << "\n";
		Serialise(OutFile, node->left);
		Serialise(OutFile, node->right);
	}
	else {
		return -1;
	}
}


// used to print out tree
/*
Title : Pretty Print
Author : StackOverflow
Link: https://stackoverflow.com/a/51730733
*/
void BinarySearchTree::pretty_print(std::string prefix, const TreeNode* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "|--" : "|__");

		// print the value of the node
		std::cout << node->data << std::endl;

		// enter the next tree level - left and right branch
		pretty_print(prefix + (isLeft ? "|   " : "    "), node->left, true);
		pretty_print(prefix + (isLeft ? "|   " : "    "), node->right, false);
	}
}

void BinarySearchTree::pretty_print(const TreeNode* node)
{
	pretty_print("", node, false);
}