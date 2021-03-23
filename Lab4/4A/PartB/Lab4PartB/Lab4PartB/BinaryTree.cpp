#include "BinaryTree.h"
#include <stddef.h>
#include <iostream>

using namespace std;

//Dylan Nelson - X00144862

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	destroy(root);
}


bool BinaryTree::Search(char value)
{
	if (root == NULL)
	{
		return false;
	}
	else
	{
		return Search(value, root);
	}
}

bool BinaryTree::Search(char value, TreeNode* node)
{
	if (value == node->data)
	{
		return true;
	}
	else if (value < node->data)
	{
		if (node->left == NULL)
		{
			return false;
		}
		else
		{
			return Search(value, node->left);
		}
	}
	else if (value > node->data)
	{
		if (node->right == NULL)
		{
			return false;
		}
		else
		{
			return Search(value, node->right);
		}
	}

	return false;
}

void BinaryTree::add(char value)
{
	TreeNode* temp = new TreeNode(value);
	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		add(temp, root);
	}
}


void BinaryTree::add(TreeNode* newNode, TreeNode* addHere)
{
	if (newNode->data < addHere->data)
	{
		if (addHere->left == NULL)
		{
			addHere->left = newNode;
		}
		else
		{
			add(newNode, addHere->left);
		}
	}
	else if (newNode->data > addHere->data)
	{
		if (addHere->right == NULL)
		{
			addHere->right = newNode;
		}
		else
		{
			add(newNode, addHere->right);
		}
	}
}



void BinaryTree::Print()
{

	Print(root);

}

void BinaryTree::Print(TreeNode* node)
{
	if (node != NULL)
	{
		Print(node->left);
		cout << node->data << " ";
		Print(node->right);
	}
}



void BinaryTree::PostOrder()
{
	PreOrder(root);
}

void BinaryTree::PostOrder(TreeNode* node)
{
	if (node != NULL)
	{
		PostOrder(node->left);
		PostOrder(node->right);
		cout << node->data << " ";
	}
}

void BinaryTree::PreOrder()
{
	Print(root);
}

void BinaryTree::PreOrder(TreeNode* node)
{
	if (node != NULL)
	{
		cout << node->data;
		PreOrder(node->left);
		PreOrder(node->right);
	}
}



void BinaryTree::destroy(TreeNode* node)
{
	if (node != NULL)
	{
		destroy(node->left);
		destroy(node->right);
		delete node;
	}
}