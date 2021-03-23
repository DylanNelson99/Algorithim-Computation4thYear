#pragma once

//Dylan Nelson - X00144862

class TreeNode {
	friend class BinarySearchTree;
	// public:
	TreeNode();
	TreeNode(int data); // for it to store integers
	~TreeNode();

private:
	int data;
	TreeNode* left;
	TreeNode* right;
};