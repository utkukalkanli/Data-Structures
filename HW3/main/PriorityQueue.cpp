#include "PriorityQueue.h"


PriorityQueue::PriorityQueue()
{
}

PriorityQueue::~PriorityQueue()
{
}

PriorityQueue::PriorityQueue(const PriorityQueue& toCopy)
{
	this->h = toCopy.h;
}

bool PriorityQueue::pqIsEmpty() const {
	return h.heapIsEmpty();
}

void PriorityQueue::pqInsert(const Patient& newItem) throw (PQException) {
	try {
		h.heapInsert(newItem);
	}
	catch (HeapException e) {
		throw PQException("Priority queue is full");
	}
}

void PriorityQueue::pqDelete(Patient& priorityItem) throw (PQException) {
	try {
		h.heapDelete(priorityItem);
	}
	catch (HeapException e) {
		throw PQException("Priority queue is empty");
	}
}

void PriorityQueue::pqPrint()
{
	h.heapPrint();
}
