#pragma once
#include "TreeNode.h"
#ifndef BinaryTree_H
#define BinaryTree_H

//Dylan Nelson - X00144862

class BinaryTree
{
public:
	BinaryTree();
	void add(int);
	void destroy(TreeNode*);
	int height();
	bool hasPathSum(TreeNode*, int);
	void printPaths(TreeNode*);
	TreeNode* getRoot();
	~BinaryTree();
private:
	int height(TreeNode*);
	void add(TreeNode*, TreeNode*);
	void printPaths(TreeNode*, int[], int);
	TreeNode* root;
};


#endif 
