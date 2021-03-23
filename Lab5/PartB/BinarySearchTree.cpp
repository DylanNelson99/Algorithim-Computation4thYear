#include "BinarySearchTree.h"
#include <fstream>
#include <iostream>
#include <string>

//Dylan Nelson - X00144862

/** Title : Print binary tree in a pretty way using c++
	Author : Unknown (Stackoverflow)
	Link: https://stackoverflow.com/a/51730733
**/

BinarySearchTree::BinarySearchTree() = default;

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

//Remove method
void BinarySearchTree::remove(int toremove)
{
	std::cout << "Trying to remove " << toremove << "...\n\n";

	if (root == nullptr) return;
	remove(toremove, root);
}
void BinarySearchTree::remove(int toremove, TreeNode * node)
{
	if (node != nullptr) {
		if (toremove < node->data) {
			remove(toremove, node->left);
		}
		else if (toremove > node->data) {
			remove(toremove, node->right);
		}
		else {
			const int* replacement_data = get_replacement_value(node);
			if (replacement_data == nullptr) {
				cut_leaf(toremove, root);
				return;
			}
			node->data = *replacement_data;

			return;
		}
	}
	else {
		std::cout << toremove << " not found" << std::endl;
		return;
	}
}
const int* BinarySearchTree::get_replacement_value(TreeNode * node)
{
	if (node == nullptr) return nullptr;

	if (node->right != nullptr) {
		if (node->right->left == nullptr && node->right->right == nullptr) {
			TreeNode* temp = node->right;
			node->right = nullptr;
			int data = temp->data;
			delete temp;
			return &data;
		}
		else if (node->right->left != nullptr) {
			TreeNode* temp = cut_leaf_on_left(node->right);
			int data = temp->data;
			delete temp;
			return &data;
		}
		else {
			TreeNode* temp = node->right;
			int data = temp->data;
			node->left = temp->left;								
			node->right = temp->right;
			delete temp;
			return &data;
		}
	}
	else if (node->left != nullptr) {							
		TreeNode* temp = node->left;
		node->left = temp->left;
		node->right = temp->right;
		const int data = temp->data;

		delete temp;
		return &data;
	}
	return nullptr;									

}
TreeNode* BinarySearchTree::cut_leaf_on_left(TreeNode * node) {
	if (node == nullptr) return nullptr;
	if (node->left->left == nullptr && node->left->right == nullptr) {
		TreeNode* temp = node->left;				
		node->left = nullptr;
		return temp;
	}
	return cut_leaf_on_left(node->left);
}
void BinarySearchTree::cut_leaf(int tocut, TreeNode * node) {
	if (node == nullptr) return;
	if (tocut < node->data) {
		if (node->left != nullptr && tocut == node->left->data) {
			delete node->left;
			node->left = nullptr;
			return;
		}
		cut_leaf(tocut, node->left);
	}
	else if (tocut > node->data) {
		if (node->right != nullptr && tocut == node->right->data) {
			delete node->right;
			node->right = nullptr;
			return;
		}
		cut_leaf(tocut, node->right);
	}
	else {					
		delete node;
		root = nullptr;
	}
}
//Pretty print method
void BinarySearchTree::pretty_print() {
	pretty_print(root);
}

int BinarySearchTree::height()
{
	return height(root);
}
int BinarySearchTree::height(TreeNode * node)
{
	if (node != nullptr) {
		int depthLeft = height(node->left);
		int depthRight = height(node->right);
		return std::max(depthLeft + 1, depthRight + 1);
	}
	else {
		return -1;
	}
}


//New tasks for lab 5b
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
		if(node == nullptr) return 1;

		OutFile << node->data << "\n";
		Serialise(OutFile, node->left);
		Serialise(OutFile, node->right);
	} else {
		return -1;
	}
}

void BinarySearchTree::pretty_print(std::string prefix, const TreeNode* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "|--" : "|__");

		// printing the value 
		std::cout << node->data << std::endl;

		pretty_print(prefix + (isLeft ? "|  " : "   "), node->left, true);
		pretty_print(prefix + (isLeft ? "|  " : "   "), node->right, false);
	}
}

void BinarySearchTree::pretty_print(const TreeNode * node)
{
	pretty_print("", node, false);
}