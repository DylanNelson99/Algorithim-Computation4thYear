#pragma once
#ifndef BinaryTree_h
#define BinaryTree_h
#include "TreeNode.h"

//Dylan Nelson - X00144862

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	bool Search(char);
	void add(char);
	void Print();
	void PreOrder();
	void PostOrder();
private:
	TreeNode* root;
	void destroy(TreeNode*);
	void add(TreeNode*, TreeNode*);
	bool Search(char, TreeNode*);
	void Print(TreeNode*);
	void PreOrder(TreeNode*);
	void PostOrder(TreeNode*);
};

#endif // BinaryTree_h
