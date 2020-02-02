#include "hw2.h" 

#include <stdlib.h>
#include <iostream>


int main(int argc, char** argv) {
	NgramTree tree;  
	int n;
	string fileName;
	if(argc > 1)
	{
		fileName = argv[1];
		n = atoi(argv[2]);
		cout << "filename readed from command line argument " << endl;
	}
	else {
	    n = 4;
        fileName = "input.txt";
		cout << "argc cannot be readed from command line argument, inner file will be used" << endl;
	}

	tree.generateTree(fileName, n);
	cout << "\nTotal " << n << " - gram count : " << tree.getTotalNgramCount() << endl;   
	tree.printNgramFrequencies();
	cout << n << " - gram tree is complete : "  << (tree.isComplete() ? "Yes" : "No") << endl; 
	cout << n << " - gram tree is full : " << (tree.isFull() ? "Yes" : "No") << endl;
	//Before insertion of new n-grams 
	tree.addNgram("samp"); 
	tree.addNgram("samp"); 
	tree.addNgram("zinc"); 
	tree.addNgram("aatt");
	cout << "\nTotal " << n << " - gram count : " << tree.getTotalNgramCount() << endl;   
	tree.printNgramFrequencies();
	cout << n << " - gram tree is complete : "  << (tree.isComplete() ? "Yes" : "No") << endl; 
	cout << n << " - gram tree is full : "  << (tree.isFull() ? "Yes" : "No") << endl; 

	/*
	string filename("utku");
	cout << filename << endl;

	cout << "Hello World" << endl;
	NgramTree* ng = new NgramTree();
	BinarySearchTree* bg = new BinarySearchTree();
	BinarySearchTree* ag = new BinarySearchTree();
	string first = "utku";
	string second = "jonas";
	string third = "ulrich";
	string fourth = "martha";
	string fifth = "hannah";
	string sixth = "claudia";
	bg->searchTreeInsert(first);
	bg->searchTreeInsert(second);
	bg->searchTreeInsert(third);
	bg->searchTreeInsert(fourth);
	bg->searchTreeInsert(fifth);
	bg->searchTreeInsert(sixth);
	bg->print();
	cout << bg->contains(first) << endl;
	cout << bg->contains(second) << endl;
	cout << bg->contains(third) << endl;
	cout << bg->contains(fourth) << endl;
	cout << bg->contains(fifth) << endl;
	cout << bg->contains(sixth) << endl;
	cout << "---------" << endl;
	bg->print();
	try {
		bg->searchTreeDelete(first);
		bg->searchTreeDelete(fourth);
		bg->searchTreeDelete(first);
		cout << " -------" << endl;
		bg->print();
	}
	catch (TreeException error) {
		cout << error.what() << endl;
	}
	cout << bg->contains(first) << endl;
	cout << bg->contains(second) << endl;
	cout << bg->contains(third) << endl;
	cout << bg->contains(fourth) << endl;
	cout << bg->contains(fifth) << endl;
	cout << bg->contains(sixth) << endl;
	cout << "---------" << endl;
	bg->print();*/
	//bg->print();
	//ag = bg;
	//cout << "---------" << endl;
	//ag->print();
	//BinarySearchTree* cg;
	//cg = new BinarySearchTree(*ag);
	//cout << "---------" << endl;
	//cg->print();
	//TreeNode* tree;
	//cg->searchTreeRetrieve(second,tree);
	//tree->printTreeNode();
	//tree->incrementCount();
	//tree->printTreeNode();
	return 0;
}

