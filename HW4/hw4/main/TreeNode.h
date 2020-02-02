#pragma once
#include <string>
using namespace std;
enum Color { RED, BLACK }; // RED = 0, BLACK = 1


class TreeNode
{
public:
	TreeNode();
	TreeNode(const string& nodeItem);
	~TreeNode();
	void incrementCount();
	void setCount(int co);
	string getItem();
	int getCount();
	void printTreeNode();
	Color getColor();
	void setColor(Color c);
	void flipColor();

	string item; 		// a data item in the tree
	TreeNode* leftChildPtr;	// pointers to children 
	TreeNode* rightChildPtr;
	TreeNode* parentPtr;
	Color     color;
	int count;


	// friend class - can access private parts
	friend class RBTree;
};

class TreeException : public exception {

private:
	string msg;

public:
	virtual const char* what() const throw()
	{
		return msg.c_str();
	}
	TreeException(const string& message = "") :
		exception(), msg(message) {};
	~TreeException() throw() {};

}; // end TreeException



