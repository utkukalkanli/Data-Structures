#pragma once
#include "RBTree.h"

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <string>
// hw4.h … 
// NgramTree class 
/* UTKU KALKANLI
*  21602325
*  hw4.h
*/

using namespace std;
class Words
{
public:
	Words();
	~Words();
	void addWord(string word);
	void generateTree(string fileName);
	void printHeight();
	int getHeight(TreeNode* root);
	int printTotalWordCount();
	void printWordFrequencies();
	TreeNode* printMostFrequent();
	TreeNode* printLeastFrequent();
	double printStandartDeviation();
	int findMean();


	string readData(string fileName);
	RBTree* rbt;
};