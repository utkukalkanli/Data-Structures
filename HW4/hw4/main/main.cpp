// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "hw4.h"
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	Words* wrd;
	string fileName;

	//treefile.open("wordfreqs.txt");

	if (argc > 1)
	{
		fileName = argv[1];
		cout << "filename readed from command line argument " << endl;
	}
	else {
		fileName = "dubliners.txt";
		cout << "argc cannot be readed from command line argument, inner file will be used" << endl;
	}
	wrd = new Words();
	wrd->generateTree(fileName);
	//wrd->printHeight();
	//wrd->printTotalWordCount();
	wrd->printWordFrequencies();
	//wrd->printMostFrequent();
	//wrd->printLeastFrequent();
	//wrd->printStandartDeviation();
	cout << endl;
	int treeheight = wrd->getHeight(wrd->rbt->root);
	cout << "tree height " << treeheight << endl;
	int totalwordCount = wrd->printTotalWordCount();
	TreeNode* leastfreq = wrd->printLeastFrequent();
	TreeNode* mostfreq = wrd->printMostFrequent();
	double standartDeviation = wrd->printStandartDeviation();
	fstream file;
	file.open("statistics.txt");
	file << "total word count is ";
	file << totalwordCount << endl;
	file << "tree height is ";
	file << treeheight << endl;
	file << "most frequent: ";
	file << mostfreq->getItem() + " ";
	file << mostfreq->getCount() << endl;
	file << "least frequent: ";
	file << leastfreq->getItem() + " ";
	file << mostfreq->getCount() << endl;
	file << "standart deviation is ";
	file << standartDeviation << endl;
	file.close();

	//treefile.close();
	return 0;
}

//int main()
//{
//    cout << "Hello Funky World!\n"; 
//	//TreeNode* tn;
//	//tn = new TreeNode("utku");
//	//tn->printTreeNode();
//	//tn->flipColor();
//	//tn->printTreeNode();
//	//TreeNode* a = new TreeNode("a");
//	//TreeNode* b = new TreeNode("b");
//	//TreeNode* c = new TreeNode("c");
//	//TreeNode* d = new TreeNode("d");
//
//	RBTree* rbtree;
//	rbtree = new RBTree();
//	rbtree->RBTInsert("1");
//	rbtree->RBTInsert("10");
//	rbtree->RBTInsert("12");
//	rbtree->RBTInsert("14");
//	rbtree->RBTInsert("16");
//	rbtree->RBTInsert("18");
//
//	//rbtree->RBTInsert("100");
//	//rbtree->RBTInsert("9");
//	//rbtree->RBTInsert("2");
//	//rbtree->RBTInsert("4");
//
//	//rbtree->RBTInsert("10");
//
//	//rbtree->printRBT();
//
//	Words *wrd = new Words();
//	wrd->addWord("a");
//	wrd->addWord("b");
//	wrd->addWord("c");
//	wrd->addWord("d");
//	wrd->addWord("e");
//	wrd->addWord("a");
//	wrd->addWord("b");
//	wrd->addWord("a");
//	wrd->addWord("e");
//	wrd->rbt->printRBT();
//
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
