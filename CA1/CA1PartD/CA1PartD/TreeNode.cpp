#include "TreeNode.h"

//Dylan Nelson - X00144862

TreeNode::TreeNode() {}

TreeNode::TreeNode(int dataIn) { data = dataIn; }

TreeNode::~TreeNode() {
	delete left;
	delete right;