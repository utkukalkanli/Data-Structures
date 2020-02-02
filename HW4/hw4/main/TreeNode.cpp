#include "TreeNode.h"
#include <iostream>
using namespace std;

TreeNode::TreeNode()
{
}

TreeNode::TreeNode(const string& nodeItem)
{
	item = nodeItem;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
	parentPtr = NULL;
	color = RED;
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

void TreeNode::setCount(int co)
{
	count = co;
}

string TreeNode::getItem()
{
	return item;
}

int TreeNode::getCount()
{
	return count;
}

void TreeNode::printTreeNode()
{
	cout << item << " " << count;
	if (color == 0) {
		cout << " " << "RED" << endl;
	}
	else {
		cout << " " << "BLACK" << endl;
	}

}

Color TreeNode::getColor()
{
	return color;
}

void TreeNode::setColor(Color c)
{
	color = c;
}

void TreeNode::flipColor()
{
	if (color == BLACK) {
		color = RED;
	}
	else {
		color = BLACK;
	}
}

