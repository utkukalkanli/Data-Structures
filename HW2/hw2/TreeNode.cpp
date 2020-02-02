#include "TreeNode.h"
#include <iostream>
/* UTKU KALKANLI
*  21602325
*  TreeNode.cpp
*/


TreeNode::TreeNode(const string& nodeItem)
{
	item = nodeItem;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
	count = 1;
	// cout << "tree node constructor " << nodeItem << endl;
}

TreeNode::~TreeNode()
{
}

void TreeNode::incrementCount()
{
	count++;
}

string TreeNode::getItem()
{
	return item;
}

int TreeNode::getCount()
{
	return count;
}

void TreeNode::printTreeNode() {
	cout << item << " " << count << endl;
}