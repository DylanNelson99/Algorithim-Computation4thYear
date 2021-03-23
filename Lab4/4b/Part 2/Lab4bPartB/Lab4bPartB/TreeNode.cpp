#include "TreeNode.h"
#include <iostream>

using namespace std;

//Dylan Nelson - X00144862

TreeNode::TreeNode() {
	data = 0;
	right = NULL;
	left = NULL;
}

TreeNode::TreeNode(int dataIn) {
	data = dataIn;
	right = NULL;
	left = NULL;
}

int TreeNode::getData() {
	return data;
}

TreeNode* TreeNode::getRight() {
	return right;
}

TreeNode* TreeNode::getLeft() {
	return left;
}