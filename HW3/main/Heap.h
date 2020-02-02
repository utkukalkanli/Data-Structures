#include <string>
#include "Patient.h"
using namespace std;
const int MAX_HEAP = 200;
//#include "KeyedItem.h"// definition of KeyedItem
//typedef KeyedItem HeapItemType;

class HeapException : public exception {

private:
	string msg;

public:
	virtual const char* what() const throw()
	{
		return msg.c_str();
	}
	HeapException(const string& message = "") :
		exception(), msg(message) {};
	~HeapException() throw() {};

}; // end TreeException


class Heap {
public:
	Heap();				// default constructor
	~Heap();
	// copy constructor and destructor are supplied by the compiler
	Heap(const Heap& toCopy);

	bool heapIsEmpty() const;
	void heapInsert(const Patient& newItem) throw(HeapException);
	void heapDelete();
	void heapDelete(Patient& rootItem) throw(HeapException);
	void heapGetTop(Patient& heapTop);
	void heapPrint();

	bool isMaxHeap();

	bool isMaxHeap(int root);

protected:
	void heapRebuild(int root);		// Converts the semiheap rooted at
								// index root into a heap
private:
	// Patient items[MAX_HEAP];	// array of heap items
	Patient* items;
	int          size;            	// number of heap items
};


