#include "TreeNode.h"
#pragma once
#pragma warning( disable : 4290 )
/* UTKU KALKANLI
*  21602325
*  BinarySearchTree.h
*/
class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& tree);
	~BinarySearchTree();

	void destroyBST();

	bool isEmpty() const;
	void print();
	void searchTreeRetrieve(string searchKey, TreeNode*& treeItem);
	void searchTreeInsert(const string& newItem);
	void searchTreeDelete(string searchKey);
	bool contains(string item);
	bool contains(TreeNode* rootPtr, string item);
	void preorderTraverse(TreeNode* treePtr);
	int getTotalCount();
	void getTotalCount(TreeNode* rootPtr, int &sum);
	int getHeight();
	int getHeight(TreeNode* root);
	bool isComplete();
	bool isComplete(TreeNode* root, int index, int nodeCount);
	void printBST();
	void inorderTraverse(TreeNode* treePtr);
	void postorderTraverse(TreeNode* treePtr);
	BinarySearchTree& operator=(const BinarySearchTree& rhs);

private:
	void retrieveItem(TreeNode* treePtr, string searchKey, TreeNode*& item);
	void insertItem(TreeNode*& treePtr, const string& newItem);
	void deleteItem(TreeNode*& treePtr, string searchKey);
	void deleteNodeItem(TreeNode*& nodePtr);
	void processLeftmost(TreeNode*& nodePtr, string& treeItem);
	void destroyTree(TreeNode*& treePtr);
	void copyTree(TreeNode* treePtr, TreeNode*& newTreePtr);

	TreeNode* root;

};

