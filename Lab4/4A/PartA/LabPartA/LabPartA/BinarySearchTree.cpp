#include "BinarySearchTree.h"
#include <stddef.h>
#include <iostream>

//Dylan Nelson - X00144862

using namespace std;

TreeNode::TreeNode()
{
	data = NULL;
}

TreeNode::TreeNode(int num)
{
	data = num;
	left = NULL;
	right = NULL;
}

BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}


void BinarySearchTree::add(TreeNode* toAdd, TreeNode* addHere)
{
	if (toAdd->data < addHere->data)
	{
		if (addHere->left == NULL)
		{
			addHere->left = toAdd;
		}
		else
		{
			add(toAdd, addHere->left);
		}
	}
	else if (toAdd->data >= addHere->data)
	{
		if (addHere->right == NULL)
		{
			addHere->right = toAdd;
		}
		else
		{
			add(toAdd, addHere->right);
		}
	}
}

void BinarySearchTree::add(int num)
{
	TreeNode* temp = new TreeNode(num);

	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		add(temp, root);
	}
}


int BinarySearchTree::height()
{
	return height(root);
}

int BinarySearchTree::height(TreeNode* node)
{
	int leftHeight = 0;
	int rightHeight = 0;

	if (root == NULL)
	{
		return -1;
	}
	else
	{

		if (node->left != NULL)
		{
			leftHeight += 1 + height(node->left);
		}

		if (node->right != NULL)
		{
			rightHeight += 1 + height(node->right);
		}

		if (leftHeight > rightHeight)
		{
			return leftHeight;
		}
		else
		{
			return rightHeight;
		}
	}

}


void BinarySearchTree::printPaths(TreeNode* node)
{
	int path[1000];
	printPaths(node, path, 0);
}

void BinarySearchTree::printPaths(TreeNode* node, int path[], int pathLen)
{
	if (node == NULL)
	{
		return;
	}

	path[pathLen] = node->data;

	if (node->left == NULL && node->right == NULL)
	{
		for (int i = 0; i <= pathLen; i++)
		{
			cout << path[i] << " ";
		}
	}
	else
	{
		printPaths(node->left, path, 1 + pathLen);
		printPaths(node->right, path, 1 + pathLen);
	}
}

TreeNode* BinarySearchTree::getRoot()
{
	return root;
}



void BinarySearchTree::destroy(TreeNode* root)
{
	if (root != NULL)
	{
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}

BinarySearchTree::~BinarySearchTree()
{
	destroy(root);
}