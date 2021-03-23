#pragma once
#ifndef BinarySearchTree_H
#define BinarySearchTree_H

//Dylan Nelson - X00144862
class TreeNode
{
	friend class BinarySearchTree;
public:
	TreeNode();
	TreeNode(int);
private:
	TreeNode* left;
	int data;
	TreeNode* right;
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	void add(int);
	void destroy(TreeNode*);
	int height();
	void printPaths(TreeNode*);
	TreeNode* getRoot();
	~BinarySearchTree();
private:
	int height(TreeNode*);
	void add(TreeNode*, TreeNode*);
	void printPaths(TreeNode*, int[], int);
	TreeNode* root;
};


#endif