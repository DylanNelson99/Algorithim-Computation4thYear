#pragma once
//Dylan Nelson - X00144862

class TreeNode {
	friend class BinaryTree;
private:
	int data;
	TreeNode* left;
	TreeNode* right;

public:
	TreeNode();
	TreeNode(int);
	int getData();
	TreeNode* getRight();
	TreeNode* getLeft();
};

