#include "BinarySearchTree.h"
#include <iostream>
#include <algorithm>    // std::max
/* UTKU KALKANLI
*  21602325
*  BinarySearchTree.cpp
*/
BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree)
{
	copyTree(tree.root, root);
}

BinarySearchTree::~BinarySearchTree()
{
	destroyTree(root);
}

void BinarySearchTree::destroyBST() {
	destroyTree(root);
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& rhs)
{
	if (this != &rhs) {
		destroyTree(root);
		root = NULL;
		BinarySearchTree(rhs);
	}
	return *this;
}


bool BinarySearchTree::isEmpty() const
{
	if (root == NULL) {
		return true;
	}
	return false;
}

void BinarySearchTree::print()
{
	inorderTraverse(root);
}

void BinarySearchTree::searchTreeRetrieve(string searchKey, TreeNode*& treeItem)
{
	retrieveItem(root, searchKey, treeItem);
}

void BinarySearchTree::searchTreeInsert(const string& newItem)
{
	insertItem(root, newItem);
}

void BinarySearchTree::searchTreeDelete(string searchKey)
{
	deleteItem(root, searchKey);
}

bool BinarySearchTree::contains(string item)
{
	return contains(root, item);
}

bool BinarySearchTree::contains(TreeNode* rootPtr, string item)
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

void BinarySearchTree::preorderTraverse(TreeNode* treePtr)
{
	if (treePtr != NULL) {
		// DO THE WORK
		cout << treePtr->item << " " << endl;
		preorderTraverse(treePtr->leftChildPtr);
		preorderTraverse(treePtr->rightChildPtr);
	}

}

int BinarySearchTree::getTotalCount() {
	int sum = 0;
	getTotalCount(root, sum);
	return sum;
}

void BinarySearchTree::getTotalCount(TreeNode* rootPtr, int& sum) {
	if (rootPtr != NULL) {
		getTotalCount(rootPtr->leftChildPtr, sum);
		sum = sum + 1;
		getTotalCount(rootPtr->rightChildPtr, sum);
	}
}

int BinarySearchTree::getHeight() {
	return getHeight(root);
}

int BinarySearchTree::getHeight(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + max(getHeight(root->leftChildPtr), getHeight(root->rightChildPtr));
	}
}

bool BinarySearchTree::isComplete() {
	return isComplete(root, 0, getTotalCount());
}

bool BinarySearchTree::isComplete(TreeNode* root, int index, int nodeCount)
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

void BinarySearchTree::printBST() {
	inorderTraverse(root);
}

void BinarySearchTree::inorderTraverse(TreeNode* treePtr)
{
	if (treePtr != NULL) {
		inorderTraverse(treePtr->leftChildPtr);
		// DO THE WORK
		treePtr->printTreeNode();
		inorderTraverse(treePtr->rightChildPtr);
	}
}

void BinarySearchTree::postorderTraverse(TreeNode* treePtr)
{
	if (treePtr != NULL) {
		postorderTraverse(treePtr->leftChildPtr);
		postorderTraverse(treePtr->rightChildPtr);
		cout << treePtr->item << " " << endl;
		// DO THE WORK
	}
}

void BinarySearchTree::retrieveItem(TreeNode* treePtr, string searchKey, TreeNode*& treeItem)
{
	if (treePtr == NULL)
		throw TreeException("TreeException: searchKey not found");
	else if (searchKey.compare(treePtr->item) == 0)
		treeItem = treePtr;
	else if (searchKey.compare(treePtr->item) < 0) // search key is alphabetically prior to treeItem
		retrieveItem(treePtr->leftChildPtr, searchKey, treeItem);
	else
		retrieveItem(treePtr->rightChildPtr, searchKey, treeItem);

}

void BinarySearchTree::insertItem(TreeNode*& treePtr, const string& newItem)
{
	// Position of insertion found; insert after leaf
	if (treePtr == NULL) {
		treePtr = new TreeNode(newItem);
		if (treePtr == NULL)
			throw TreeException("TreeException: insert failed");
	}
	// Else search for the insertion position
	else if(newItem.compare(treePtr->item) < 0)
		insertItem(treePtr->leftChildPtr, newItem);
	else
		insertItem(treePtr->rightChildPtr, newItem);
}

void BinarySearchTree::deleteItem(TreeNode*& treePtr, string searchKey)
{
	if (treePtr == NULL) // Empty tree
	{
		throw TreeException("Delete failed");
	}
	// Position of deletion found
	else if (searchKey.compare(treePtr->item) == 0)
		deleteNodeItem(treePtr);
	// Else search for the deletion position
	else if (searchKey.compare(treePtr->item) < 0)
		deleteItem(treePtr->leftChildPtr, searchKey);
	else
		deleteItem(treePtr->rightChildPtr, searchKey);
}

void BinarySearchTree::deleteNodeItem(TreeNode*& nodePtr)
{
	TreeNode* delPtr;
	string replacementItem;


	// (1)  Test for a leaf
	if ((nodePtr->leftChildPtr == NULL) &&
		(nodePtr->rightChildPtr == NULL)) {
		delete nodePtr;
		nodePtr = NULL;
	}


	// (2)  Test for no left child
	else if (nodePtr->leftChildPtr == NULL) {
		delPtr = nodePtr;
		nodePtr = nodePtr->rightChildPtr;
		delPtr->rightChildPtr = NULL;
		delete delPtr;
	}
	// (3)  Test for no right child
	else if (nodePtr->rightChildPtr == NULL) {
		// ...
        // Left as an exercise 
		delPtr = nodePtr;
		nodePtr = nodePtr->leftChildPtr;
		delPtr->leftChildPtr = NULL;
		delete delPtr;
	}
	// (4)  There are two children:
	//      Retrieve and delete the inorder successor
	else {
		processLeftmost(nodePtr->rightChildPtr, replacementItem);
		nodePtr->item = replacementItem;
	}

}

void BinarySearchTree::processLeftmost(TreeNode*& nodePtr, string& treeItem)
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


// Uses postorder traversal for the destroy operation
// (Visits first the left and right children and then the node)
void BinarySearchTree::destroyTree(TreeNode*& treePtr) {

	if (treePtr != NULL) {
		destroyTree(treePtr->leftChildPtr);
		destroyTree(treePtr->rightChildPtr);
		delete treePtr;
		treePtr = NULL;
	}
}

// Uses preorder traversal for the copy operation
// (Visits first the node and then the left and right children)
void BinarySearchTree::copyTree(TreeNode* treePtr, TreeNode*& newTreePtr){

	if (treePtr != NULL) {		// copy node
		newTreePtr = new TreeNode(treePtr->item);
		copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
		copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
	}
	else
		newTreePtr = NULL;	// copy empty tree
}


