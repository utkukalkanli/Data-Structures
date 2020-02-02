#include "Heap.h"// ADT heap operations
//typedef HeapItemType PQItemType;
#include "Patient.h"

class PQException : public exception {

private:
	string msg;

public:
	virtual const char* what() const throw()
	{
		return msg.c_str();
	}
	PQException(const string& message = "") :
		exception(), msg(message) {};
	~PQException() throw() {};

}; // end TreeException


class PriorityQueue {
public:
	PriorityQueue();
	~PriorityQueue();
	// default constructor, copy constructor, and destructor 
	// are supplied by the compiler
	PriorityQueue(const PriorityQueue& toCopy);
	// priority-queue operations:
	bool pqIsEmpty() const;
	void pqInsert(const Patient& newItem) throw (PQException);
	void pqDelete(Patient& priorityItem) throw (PQException);
	void pqPrint();
	
	Heap h;
};
