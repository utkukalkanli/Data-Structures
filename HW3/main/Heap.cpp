#include "Heap.h"
#include <iostream>

// Default constructor 
Heap::Heap() {
	size = 0;
	items = new Patient[MAX_HEAP];
}

Heap::~Heap() {
	if (items != NULL) {
		delete items;
		items = NULL;
	}
}

Heap::Heap(const Heap& toCopy)
{
	this->size = toCopy.size;
	items = new Patient[size];
	for (int i = 0; i < size; i++) {
		items[i] = toCopy.items[i];
	}
}


bool Heap::heapIsEmpty() const {
	return (size == 0);
}

void Heap::heapInsert(const Patient& newItem) throw(HeapException) {

	if (size >= MAX_HEAP)
		throw HeapException("HeapException: Heap full");

	// Place the new item at the end of the heap
	items[size] = newItem;

	// Trickle new item up to its proper position
	int place = size;
	int parent = (place - 1) / 2;
	while ((place > 0) && (items[place].getPatientPriority() > items[parent].getPatientPriority())) {
		Patient temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;

		place = parent;
		parent = (place - 1) / 2;
	}
	++size;
}


void Heap::heapDelete() {
	heapDelete(items[0]);
}


void Heap::heapDelete(Patient& rootItem) throw(HeapException) {
	if (heapIsEmpty())
		throw HeapException("HeapException: Heap empty");
	else {
		rootItem = items[0];
		items[0] = items[--size];
		heapRebuild(0);

	}
}

void Heap::heapGetTop(Patient& heapTop)
{
	heapTop = items[0];
}

void Heap::heapPrint() {

	for(int i = 0; i < size; i++){
		items[i].printPatient();
	}
}


bool Heap::isMaxHeap() {
	return isMaxHeap(0);
}

bool Heap::isMaxHeap(int root) {
	int leftChild = 2 * root + 1;
	int rightChild = leftChild + 1;
	bool flag = true;
	if (leftChild > size)
		return true;

	if (items[root].getPatientPriority() < items[leftChild].getPatientPriority() || items[root].getPatientPriority() < items[rightChild].getPatientPriority())
		flag = false;

	return flag && isMaxHeap(leftChild) && isMaxHeap(rightChild);
}


void Heap::heapRebuild(int root) {
	int child = 2 * root + 1; 	// index of root's left child, if any
	if (child < size) {
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ((rightChild < size) &&
			(items[rightChild].getPatientPriority() > items[child].getPatientPriority()))
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if (items[root].getPatientPriority() < items[child].getPatientPriority()) {
			Patient temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
	}
}