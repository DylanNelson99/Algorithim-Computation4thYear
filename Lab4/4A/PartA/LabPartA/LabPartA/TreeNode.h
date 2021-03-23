#pragma once
#ifndef TreeNode_h
#define TreeNode_h

//Dylan Nelson - X00144862

class TreeNode
{
	friend class BinarySearchTree;
public:
	TreeNode();
	TreeNode(int);
private:
	int data;
	TreeNode* left;
	TreeNode* right;
};


#endif 