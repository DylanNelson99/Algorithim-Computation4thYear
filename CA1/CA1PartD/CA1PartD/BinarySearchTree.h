#pragma once
#include "TreeNode.h"
#include <string>
#include <fstream>

//Dylan Nelson - X00144862

using std::ofstream;
using std::ifstream;

class BinarySearchTree
{

	friend class TreeNode;

public:
	BinarySearchTree(); //  create empty tree 
	~BinarySearchTree(); // destructor
	void destruct_tree();
	int Serialise(ofstream& OutFile); 
	void add(int toadd);
	int Deserialise(ifstream& InFile); //read bst from txt file
	int Serialise(ofstream& OutFile, TreeNode* root);
	void pretty_print(); // output method

private:
	void destruct_tree(TreeNode* node);

	int Serialise(ofstream& OutFile, TreeNode* root);
	void add(int toadd, TreeNode* node);

	void pretty_print(const TreeNode* node);
	void pretty_print(std::string prefix, const TreeNode* node, bool isLeft);
};

