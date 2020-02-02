#include "hw2.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>

/* UTKU KALKANLI 
*  21602325
*  hw2.cpp
*/
using namespace std;


NgramTree::NgramTree()
{
	bst = new BinarySearchTree();
}

NgramTree::~NgramTree()
{
	bst->destroyBST();
}



bool NgramTree::isComplete()
{
	return bst->isComplete();
}

bool NgramTree::isFull()
{
	int height = bst->getHeight();
	int nodeCount = getTotalNgramCount();
	if ((pow(2, height) - 1) == nodeCount) {
		return true;
	}
	return false;
}

void NgramTree::addNgram(string ngram)
{
	if (bst->contains(ngram)) {
		TreeNode* changingNode;
		bst->searchTreeRetrieve(ngram, changingNode);
		changingNode->incrementCount();
		changingNode = NULL;
		delete changingNode;
	}
	else {
		bst->searchTreeInsert(ngram);
	}
}
void NgramTree::generateTree(string fileName, int n)
{
	string myinput = readData(fileName);
	string delimiter = " ";
	size_t pos = 0;
	string array[100];
	int i = 0;
	int numberOfWords = 0;
	string token;
	while ((pos = myinput.find(delimiter)) != string::npos) {
		token = myinput.substr(0, pos);
		array[i] = token;
		i++;
		numberOfWords++;
		myinput.erase(0, pos + delimiter.length());
	}
	for (int i = 0; i < numberOfWords; i++) {
		if (array[i].length() >= n) {
			int start = 0;
			int finish = n;
			int turn = array[i].length() - n + 1;
			for (int k = 0; k < turn; k++) {
				addNgram(array[i].substr(start + k, finish));
			}
		}
	}

}
void NgramTree::printNgramFrequencies()
{
	bst->printBST();
}

int NgramTree::getTotalNgramCount()
{
	return bst->getTotalCount();
}

string NgramTree::readData(string fileName) 
{
	string inputline;
	//ifstream file(fileName.c_str());
	//if (file.is_open()) {
	//	while (getline(file, inputline)) {
	//		// inputline = inputline + inputline;
	//	}
	//	file.close();
	//}
	//else {
	//	cout << "file is not open" << endl;
	//}
	fstream file;
	file.open(fileName.c_str());
	while (getline(file, inputline)){
	}
	file.close();
	cout << inputline << endl;
	return inputline;
}


