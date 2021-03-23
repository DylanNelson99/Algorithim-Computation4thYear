#pragma once
#include "TreeNode.h"
#include <string>
#include <fstream>


using std::ofstream;
using std::ifstream;

//Dylan Nelson - X00144862

class BinarySearchTree
{
	friend class TreeNode;
public:
	BinarySearchTree();
	~BinarySearchTree();
	
	void add(int toadd);
	void remove(int toremove);
	int height();

	//implementation of tasks
	int Serialise(ofstream& OutFile);
	int Deserialise(ifstream& InFile);
	
	//Pretty print method
	void pretty_print();

private:
	//tasks from lab 4a
	void add(int toadd, TreeNode* node);
	void remove(int toremove, TreeNode* node);
	int height(TreeNode* node);
	const int* get_replacement_value(TreeNode* node);
	TreeNode* cut_leaf_on_left(TreeNode* node);
	void cut_leaf(int tocut, TreeNode* node);
	int Serialise (ofstream& OutFile, TreeNode * root);
	void pretty_print(const TreeNode* node);
	void pretty_print(std::string prefix, const TreeNode* node, bool isLeft);
	
	TreeNode* root;
};

