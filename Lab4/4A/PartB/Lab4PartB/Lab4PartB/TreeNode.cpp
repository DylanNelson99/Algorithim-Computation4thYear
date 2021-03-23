#include "TreeNode.h"
#include <stddef.h>

//Dylan Nelson - X00144862

TreeNode::TreeNode()
{
	data = NULL;
	left = NULL;
	right = NULL;
}

TreeNode::TreeNode(char value)
{
	data = value;
	left = NULL;
	right = NULL;
}

TreeNode::~TreeNode()
{
}