#include <string>
/* UTKU KALKANLI
*  21602325
*  TreeNode.h
*/
using namespace std;
class TreeNode { 	// a node in the tree
public:
	TreeNode() { }
	TreeNode(const string& nodeItem);
	~TreeNode();
	void incrementCount();
	string getItem();
	int getCount();
	void printTreeNode();

	string item; 		// a data item in the tree
	TreeNode* leftChildPtr;	// pointers to children 
	TreeNode* rightChildPtr;
	int count;


	// friend class - can access private parts
	friend class BinarySearchTree;
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
