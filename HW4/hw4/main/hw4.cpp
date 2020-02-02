#include "hw4.h"




Words::Words()
{
	rbt = new RBTree();
}

Words::~Words()
{
	rbt->destroyRBT();
}

void Words::addWord(string word)
{
	if (rbt->contains(word)) {
		TreeNode* changingNode;
		rbt->RBTRetrieve(word, changingNode);
		changingNode->incrementCount();
		changingNode = NULL;
		delete changingNode;
	}
	else {
		rbt->RBTInsert(word);
	}
}

void Words::generateTree(string fileName)
{
	string myinput = readData(fileName);

	//cout << "IN THE GENERATE TREE" << endl;
	//cout << myinput << endl;

	string delimiter = " ";
	string delimiterPunc = "'";
	string delimiterDot = ".";
	string delimiterDoubleDot = ":";
	string delimiterComma = ",";
	string delimiterParanthesis = ")";
	string delimiterOppositePara = "(";
	string delimiterQuotation = "\"";


	size_t pos = 0;
	size_t puncpos = 0;
	size_t dotpos = 0;
	size_t doubledotpos = 0;
	size_t commapos = 0;
	size_t paranthesispos = 0;
	size_t oppositeparapos = 0;
	size_t quotationpos = 0;

	// string array[1000];
	int i = 0;
	int numberOfWords = 0;
	string token;
	//while ((pos = myinput.find(delimiter)) != string::npos) {
	//	token = myinput.substr(0, pos);
	//	array[i] = token;
	//	i++;
	//	numberOfWords++;
	//	myinput.erase(0, pos + delimiter.length());
	//}
	while ((pos = myinput.find(delimiter)) != string::npos) {
		token = myinput.substr(0, pos);
		if((puncpos = token.find(delimiterPunc)) != string::npos) { // PUNCTUATİON '
			string token1 = token.substr(0, puncpos);
			string token2 = token.substr(puncpos + 1, pos - puncpos);
			addWord(token1);
			addWord(token2);
			//array[i] = token1;
			//array[i + 1] = token2;
			i = i + 2;
			numberOfWords = numberOfWords + 2;
			myinput.erase(0, pos + delimiter.length());
		}
		else if ((dotpos = token.find(delimiterDot)) != string::npos) {
			string token1 = token.substr(0, dotpos);
			addWord(token1);
			//array[i] = token1;
			i++;
			numberOfWords++;
			myinput.erase(0, pos + delimiter.length());
		}
		else if ((commapos = token.find(delimiterComma)) != string::npos) {
			string token1 = token.substr(0, commapos);
			addWord(token1);
			//array[i] = token1;
			i++;
			numberOfWords++;
			myinput.erase(0, pos + delimiter.length());
		}
		else if ((doubledotpos = token.find(delimiterDoubleDot)) != string::npos) {
			string token1 = token.substr(0, doubledotpos);
			addWord(token1);
			//array[i] = token1;
			i++;
			numberOfWords++;
			myinput.erase(0, pos + delimiter.length());
		}
		else if ((paranthesispos = token.find(delimiterParanthesis) != string::npos)) {
			string token1 = token.substr(0, paranthesispos);
			addWord(token1);
	     	//array[i] = token1;
			i++;
			numberOfWords++;
			myinput.erase(0, pos + delimiter.length());
		}
		else if ((oppositeparapos = token.find(delimiterOppositePara) != string::npos)) {
			string token1 = token.substr(oppositeparapos, pos - 1);
			addWord(token1);
			//array[i] = token1;
			i++;
			numberOfWords++;
			myinput.erase(0, pos + delimiter.length());
		}
		else if ((quotationpos = token.find(delimiterQuotation) != string::npos)) {
			string token1 = token.substr(quotationpos, pos - 1);
			addWord(token1);
			//array[i] = token1;
			i++;
			numberOfWords++;
			myinput.erase(0, pos + delimiter.length());
		}
		else {  
			addWord(token);  // NO PUNCTUATİON
			//array[i] = token;
			i++;
			numberOfWords++;
			myinput.erase(0, pos + delimiter.length());
		}
	}


	//for (int j = 0; j < numberOfWords; j++) {
	//	addWord(array[j]);
	//}



	//for (int i = 0; i < numberOfWords; i++) {
	//	if (array[i].length() >= n) {
	//		int start = 0;
	//		int finish = n;
	//		int turn = array[i].length() - n + 1;
	//		for (int k = 0; k < turn; k++) {
	//			addNgram(array[i].substr(start + k, finish));
	//		}
	//	}
	//}


}

string Words::readData(string fileName)
{
	string inputline;
	string word;
	fstream file;
	file.open(fileName.c_str());
	// extracting words from the file 
	while (file >> word)
	{
		inputline = inputline + " " + word;
	}
	file.close();
	return inputline;
}


void Words::printWordFrequencies()
{
	rbt->printRBT();
}

TreeNode* Words::printMostFrequent()
{
	cout << "Most frequent word is: ";
	TreeNode* mostfreq = rbt->findMostFrequent();
	mostfreq->printTreeNode();
	return mostfreq;
	
}

TreeNode* Words::printLeastFrequent()
{
	cout << "Least frequent word is: ";
	TreeNode* leastfreq = rbt->findLeastFrequent();
	leastfreq->printTreeNode();
	return leastfreq;
}

double Words::printStandartDeviation()
{
	int mean = findMean();
	//cout << "mean is " << mean << endl;
	int samplevarience = rbt->getSampleVarience(mean);
	//cout << "sample varience is : " << samplevarience << endl;
	int numberofwords = rbt->getTotalCount();
	double result = samplevarience / (numberofwords - 1);
	result = sqrt(result);
	cout << "Standart deviation is: " << result << endl;
	return result;
}

int Words::findMean()
{
	int mean;
	int countSum = rbt->getFrequencySum();
	int totalCount = rbt->getTotalCount();
	//cout << "count sum is " << countSum << endl;
	//cout << "number of nodes is " << totalCount << endl;
	mean = countSum / totalCount;
	//cout << "mean is " << mean << endl;
	return mean;
}

void Words::printHeight()
{
	cout << "Height of the tree is " << getHeight(rbt->root) << endl;
}

int Words::getHeight(TreeNode* root)
{
	if (root == NULL) {
		return 0;
	}
	else {
		return 1 + max(getHeight(root->leftChildPtr), getHeight(root->rightChildPtr));
	}
}

int Words::printTotalWordCount()
{
	cout << "Total word count is " << rbt->getTotalCount() << endl;
	return rbt->getTotalCount();
	//string result = " Total word count is: " + rbt->getTotalCount();
	//filestatistics << result << endl;
	//filestatistics.close();
}
