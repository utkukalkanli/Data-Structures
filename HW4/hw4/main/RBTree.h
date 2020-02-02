
#include "TreeNode.h"
#pragma once
#pragma warning( disable : 4290 )
/* UTKU KALKANLI
*  21602325
*  BinarySearchTree.h
*/
class RBTree
{
public:
	RBTree();
	RBTree(const RBTree& tree);
	~RBTree();

	void destroyRBT();

	bool isEmpty() const;
	void print();
	void RBTRetrieve(string searchKey, TreeNode*& treeItem);
	void RBTInsert(const string& newItem);
	void fixViolation(TreeNode*& pt);
	void fixViolation(TreeNode*& root, TreeNode*& pt);
	void rotateLeft(TreeNode*& root, TreeNode*& pt);
	void rotateRight(TreeNode*& root, TreeNode*& pt);
	//void fixTree(TreeNode* newNode);
	//void leftRotate(TreeNode* t1);
	//void rightRotate(TreeNode* t1);
	TreeNode* findMostFrequent();
	TreeNode* findMostFrequent(TreeNode* root);
	TreeNode* findLeastFrequent();
	TreeNode* findLeastFrequent(TreeNode* root);

	int getFrequencySum();
	void getFrequencySum(TreeNode* root, int &sum);

	int getSampleVarience(int mean);
	void getSampleVarience(TreeNode* root, int& samplevarience, int mean);


	bool contains(string item);
	bool contains(TreeNode* rootPtr, string item);
	void preorderTraverse(TreeNode* treePtr);
	int getTotalCount();
	void getTotalCount(TreeNode* rootPtr, int& sum);
	int getHeight();
	int getHeight(TreeNode* root);
	bool isComplete();
	bool isComplete(TreeNode* root, int index, int nodeCount);
	void printRBT();
	void inorderTraverse(TreeNode* treePtr);
	void postorderTraverse(TreeNode* treePtr);

	RBTree& operator=(const RBTree& rhs);


	void retrieveItem(TreeNode* treePtr, string searchKey, TreeNode*& item);
	void insertItem(TreeNode*& treePtr, const string& newItem);
	void processLeftmost(TreeNode*& nodePtr, string& treeItem);
	void destroyTree(TreeNode*& treePtr);
	void copyTree(TreeNode* treePtr, TreeNode*& newTreePtr);

	TreeNode* root;


};
