#pragma once
#ifndef TreeNode_h
#define TreeNode_h

//Dylan Nelson - X00144862

class TreeNode
{
	friend class BinaryTree;
public:
	TreeNode();
	TreeNode(char);
	~TreeNode();
private:
	char data;
	TreeNode* left;
	TreeNode* right;
};


#endif // TreeNode_h
