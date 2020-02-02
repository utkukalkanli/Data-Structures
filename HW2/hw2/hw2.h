#include <string>
#include "BinarySearchTree.h"
// hw2.h … 
// NgramTree class 
/* UTKU KALKANLI
*  21602325
*  hw2.h
*/
using namespace std;
class NgramTree
{
public:
	NgramTree();
	~NgramTree();
	void addNgram(string ngram);
	bool isComplete();
	bool isFull();
	void generateTree(string fileName, int n);
	void printNgramFrequencies();
	int getTotalNgramCount();

	string readData(string fileName);
	BinarySearchTree* bst;
};