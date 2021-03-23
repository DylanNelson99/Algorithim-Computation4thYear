#pragma once
#include "TreeNode.h"
#ifndef BinaryTree_H
#define BinaryTree_H

//Dylan Nelson - X00144862

class BinaryTree
{
public:
	bool isBSTV1(TreeNode*);
	bool isBST2(TreeNode*);
	int minValue(TreeNode*);
	int maxValue(TreeNode*);
	TreeNode* getRoot();
	BinaryTree();
	void add(int);
	void destroy(TreeNode*);
	int height();
	~BinaryTree();
private:
	int height(TreeNode*);
	void add(TreeNode*, TreeNode*);
	bool isBST2(TreeNode*, int, int);
	TreeNode* root;
};

#endif
