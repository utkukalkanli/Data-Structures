#include "RBTree.h"
#include <iostream>
#include <algorithm>    // std::max
using namespace std;

RBTree::RBTree()
{
	root = NULL;
}

RBTree::RBTree(const RBTree& tree)
{
	copyTree(tree.root, root);
}


RBTree::~RBTree()
{
	destroyTree(root);
}

void RBTree::destroyRBT()
{
	destroyTree(root);
}

bool RBTree::isEmpty() const
{
	if (root == NULL) {
		return true;
	}
	return false;
}

void RBTree::print()
{
	inorderTraverse(root);
}

void RBTree::RBTRetrieve(string searchKey, TreeNode*& treeItem)
{
	retrieveItem(root, searchKey, treeItem);
}

void RBTree::RBTInsert(const string& newItem)
{
	TreeNode* temp;
	TreeNode* prev;
	TreeNode* newNode = new TreeNode(newItem);
	temp = root;
	prev = NULL;

	if (root == NULL)
	{
		root = newNode;
		newNode->parentPtr = NULL;
	}
	else
	{
		while (temp != NULL)
		{
			prev = temp;
			if (temp->getItem().compare(newNode->getItem()) < 0)
				temp = temp->rightChildPtr;
			else
				temp = temp->leftChildPtr;
		}
		newNode->parentPtr = prev;
		if (prev->getItem().compare(newNode->getItem()) < 0)
			prev->rightChildPtr = newNode;
		else
			prev->leftChildPtr = newNode;
	}
	//cout << " fizz treey ";
	//newNode->printTreeNode();
	fixViolation(newNode);
	//fixTree(newNode);
}

void RBTree::fixViolation(TreeNode*& pt) {
	fixViolation(root, pt);
}


// This function fixes violations caused by BST insertion 
void RBTree::fixViolation(TreeNode*& root, TreeNode*& point)
{
		TreeNode* parent = NULL;
		TreeNode* grandParent = NULL;

		while ((point != root) && (point->color != BLACK) && (point->parentPtr->color == RED))
		{

			parent = point->parentPtr;
			grandParent = point->parentPtr->parentPtr;

			/*  Case : A
				Parent of pt is left child of Grand-parent of pt */
			if (parent == grandParent->leftChildPtr)
			{

				TreeNode* uncle = grandParent->rightChildPtr;

				/* Case : 1
				   The uncle of pt is also red
				   Only Recoloring required */
				if (uncle != NULL && uncle->color == RED)
				{
					grandParent->color = RED;
					parent->color = BLACK;
					uncle->color = BLACK;
					point = grandParent;
				}

				else
				{
					/* Case : 2
					   pt is right child of its parent
					   Left-rotation required */
					if (point == parent->rightChildPtr)
					{
						rotateLeft(root, parent);
						point = parent;
						parent = point->parentPtr;
					}
					/* Case : 3
					   pt is left child of its parent
					   Right-rotation required */
					rotateRight(root, grandParent);
					// swap(parent_pt->color, grand_parent_pt->color);
					Color ptc = parent->getColor();
					parent->setColor(grandParent->color);
					grandParent->setColor(ptc);
					point = parent;
				}
			}
			/* Case : B
			   Parent of pt is right child of Grand-parent of pt */
			else
			{
				TreeNode* uncle = grandParent->leftChildPtr;
				/*  Case : 1
					The uncle of pt is also red
					Only Recoloring required */
				if ((uncle != NULL) && (uncle->color == RED))
				{
					grandParent->color = RED;
					parent->color = BLACK;
					uncle->color = BLACK;
					point = grandParent;
				}
				else
				{
					/* Case : 2
					   pt is left child of its parent
					   Right-rotation required */
					if (point == parent->leftChildPtr)
					{
						rotateRight(root, parent);
						point = parent;
						parent = point->parentPtr;
					}
					/* Case : 3
					   pt is right child of its parent
					   Left-rotation required */
					rotateLeft(root, grandParent);
					//swap(parent_pt->color, grand_parent_pt->color);
					Color ptc = parent->getColor();
					parent->setColor(grandParent->color);
					grandParent->setColor(ptc);
					point = parent;
				}
			}
		}
		root->setColor(BLACK);
}

void RBTree::rotateLeft(TreeNode*& root, TreeNode*& point)
{
		TreeNode* pointerRight = point->rightChildPtr;

		point->rightChildPtr = pointerRight->leftChildPtr;

		if (point->rightChildPtr != NULL)
			point->rightChildPtr->parentPtr = point;

		pointerRight->parentPtr = point->parentPtr;

		if (point->parentPtr == NULL)
			root = pointerRight;

		else if (point == point->parentPtr->leftChildPtr)
			point->parentPtr->leftChildPtr = pointerRight;

		else
			point->parentPtr->rightChildPtr = pointerRight;

		pointerRight->leftChildPtr = point;
		point->parentPtr = pointerRight;
}

void RBTree::rotateRight(TreeNode*& root, TreeNode*& point)
{
		TreeNode* pointerLeft = point->leftChildPtr;

		point->leftChildPtr = pointerLeft->rightChildPtr;

		if (point->leftChildPtr != NULL)
			point->leftChildPtr->parentPtr = point;

		pointerLeft->parentPtr = point->parentPtr;

		if (point->parentPtr == NULL)
			root = pointerLeft;

		else if (point == point->parentPtr->leftChildPtr)
			point->parentPtr->leftChildPtr = pointerLeft;

		else
			point->parentPtr->rightChildPtr = pointerLeft;

		pointerLeft->rightChildPtr = point;
		point->parentPtr = pointerLeft;
}

bool RBTree::contains(string item)
{
	return contains(root, item);
}

bool RBTree::contains(TreeNode* rootPtr, string item)
{
	if (rootPtr == NULL) {
		return false;
	}
	else if (item.compare(rootPtr->item) == 0)
		return true;
	else if (item.compare(rootPtr->item) > 0)
		return contains(rootPtr->rightChildPtr, item);
	else
		return contains(rootPtr->leftChildPtr, item);
}

void RBTree::preorderTraverse(TreeNode* treePtr)
{
	if (treePtr != NULL) {
		// DO THE WORK
		cout << treePtr->item << " " << endl;
		preorderTraverse(treePtr->leftChildPtr);
		preorderTraverse(treePtr->rightChildPtr);
	}
}

int RBTree::getTotalCount()
{
	int sum = 0;
	getTotalCount(root, sum);
	return sum;
}

void RBTree::getTotalCount(TreeNode* rootPtr, int& sum)
{
	if (rootPtr != NULL) {
		getTotalCount(rootPtr->leftChildPtr, sum);
		sum = sum + 1;
		getTotalCount(rootPtr->rightChildPtr, sum);
	}
}

int RBTree::getFrequencySum()
{
	int sum = 0;
	getFrequencySum(root, sum);
	return sum;
}

void RBTree::getFrequencySum(TreeNode* rootPtr, int& sum)
{
	if (rootPtr != NULL) {
		getFrequencySum(rootPtr->leftChildPtr, sum);
		sum = sum + rootPtr->getCount();
		getFrequencySum(rootPtr->rightChildPtr, sum);
	}
}

int RBTree::getSampleVarience(int mean)
{
	int samplevarience = 0;
	getSampleVarience(root, samplevarience, mean);
	return samplevarience;
}

void RBTree::getSampleVarience(TreeNode* rootPtr, int& samplevarience, int mean)
{
	if (rootPtr != NULL) {
		getSampleVarience(rootPtr->leftChildPtr, samplevarience, mean);
		int difference = rootPtr->getCount() - mean;
		//cout << difference << endl;
		difference = difference *  difference;
		//cout << difference << endl;
		samplevarience += difference;
		getSampleVarience(rootPtr->rightChildPtr, samplevarience, mean);
	}

}

int RBTree::getHeight()
{
	return getHeight(root);
}

int RBTree::getHeight(TreeNode* root)
{
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + max(getHeight(root->leftChildPtr), getHeight(root->rightChildPtr));
	}
}

bool RBTree::isComplete()
{
	return isComplete(root, 0, getTotalCount());
}

bool RBTree::isComplete(TreeNode* root, int index, int nodeCount)
{
	// An empty tree is complete 
	if (root == NULL)
		return (true);
	// If index assigned to current node is more than 
	// number of nodes in tree, then tree is not complete 
	if (index >= nodeCount)
		return (false);
	// Recur for left and right subtrees 
	return (isComplete(root->leftChildPtr, 2 * index + 1, nodeCount) && isComplete(root->rightChildPtr, 2 * index + 2, nodeCount));
}

void RBTree::printRBT()
{
	inorderTraverse(root);
}

void RBTree::inorderTraverse(TreeNode* treePtr)
{
	if (treePtr != NULL) {
		inorderTraverse(treePtr->leftChildPtr);
		// DO THE WORK
		treePtr->printTreeNode();
		inorderTraverse(treePtr->rightChildPtr);
	}
}

void RBTree::postorderTraverse(TreeNode* treePtr)
{
	if (treePtr != NULL) {
		postorderTraverse(treePtr->leftChildPtr);
		postorderTraverse(treePtr->rightChildPtr);
		cout << treePtr->item << " " << endl;
		// DO THE WORK
	}
}

TreeNode* RBTree::findMostFrequent()
{
	if (root == NULL) {
		throw TreeException("empty tree");
	}
	else {
		return findMostFrequent(root);
	}
}

TreeNode* RBTree::findMostFrequent(TreeNode* root)
{
	
	if (root == NULL) {
		return NULL;
	}
	TreeNode* result = root;
	TreeNode* leftResult = findMostFrequent(root->leftChildPtr);
	TreeNode* rightResult = findMostFrequent(root->rightChildPtr);

	if (leftResult == NULL) {
		leftResult = new TreeNode();
	}
	if(rightResult == NULL){
		rightResult = new TreeNode();
	}
	if (leftResult->getCount() > rightResult->getCount()) {
		result = leftResult;
	}
	if (rightResult->getCount() > result->getCount()) {
		result = rightResult;
	}
	return result;
}

TreeNode* RBTree::findLeastFrequent()
{
	if (root == NULL) {
		throw TreeException("empty tree");
	}
	else {
		return findLeastFrequent(root);
	}
}

TreeNode* RBTree::findLeastFrequent(TreeNode* root)
{
	if (root == NULL) {
		return NULL;
	}
	TreeNode* result = root;
	TreeNode* leftResult = findLeastFrequent(root->leftChildPtr);
	TreeNode* rightResult = findLeastFrequent(root->rightChildPtr);

	if (leftResult == NULL) {
		leftResult = new TreeNode();
		leftResult->setCount(100000);
	}
	if (rightResult == NULL) {
		rightResult = new TreeNode();
		rightResult->setCount(100000);
	}

	if (leftResult->getCount() < rightResult->getCount()) {
		result = leftResult;
	}
	if (rightResult->getCount() < result->getCount()) {
		result = rightResult;
	}
	return result;
}

RBTree& RBTree::operator=(const RBTree& rhs)
{
	if (this != &rhs) {
		destroyTree(root);
		root = NULL;
		RBTree(rhs);
	}
	return *this;
}

void RBTree::retrieveItem(TreeNode* treePtr, string searchKey, TreeNode*& item)
{
	if (treePtr == NULL)
		throw TreeException("TreeException: searchKey not found");
	else if (searchKey.compare(treePtr->item) == 0)
		item = treePtr;
	else if (searchKey.compare(treePtr->item) < 0) // search key is alphabetically prior to treeItem
		retrieveItem(treePtr->leftChildPtr, searchKey, item);
	else
		retrieveItem(treePtr->rightChildPtr, searchKey, item);
}

void RBTree::insertItem(TreeNode*& treePtr, const string& newItem)
{
	// Position of insertion found; insert after leaf
	if (treePtr == NULL) {
		treePtr = new TreeNode(newItem);
		if (treePtr == NULL)
			throw TreeException("TreeException: insert failed");
	}
	// Else search for the insertion position
	else if (newItem.compare(treePtr->item) < 0)
		insertItem(treePtr->leftChildPtr, newItem);
	else
		insertItem(treePtr->rightChildPtr, newItem);
}

void RBTree::processLeftmost(TreeNode*& nodePtr, string& treeItem)
{
	if (nodePtr->leftChildPtr == NULL) {
		treeItem = nodePtr->item;
		TreeNode* delPtr = nodePtr;
		nodePtr = nodePtr->rightChildPtr;
		delPtr->rightChildPtr = NULL; // defense
		delete delPtr;
	}
	else
		processLeftmost(nodePtr->leftChildPtr, treeItem);
}

void RBTree::destroyTree(TreeNode*& treePtr)
{
	if (treePtr != NULL) {
		destroyTree(treePtr->leftChildPtr);
		destroyTree(treePtr->rightChildPtr);
		delete treePtr;
		treePtr = NULL;
	}
}

void RBTree::copyTree(TreeNode* treePtr, TreeNode*& newTreePtr)
{
	if (treePtr != NULL) {		// copy node
		newTreePtr = new TreeNode(treePtr->item);
		copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
		copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
	}
	else
		newTreePtr = NULL;	// copy empty tree
}
