#pragma once

//Dylan Nelson - X00144862

class TreeNode
{
	
	friend class BinarySearchTree;
public:
	TreeNode();
	TreeNode(int data);
	~TreeNode();

private:
	int data;
	TreeNode* left;
	TreeNode* right;
};
