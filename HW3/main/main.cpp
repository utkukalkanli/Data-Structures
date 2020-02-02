#include "simulator.h"

#include <stdlib.h>
#include <iostream>


int main(int argc, char** argv) {
	simulator s;
	int n;
	string fileName;
	if (argc > 1) {
		fileName = argv[1];
		n = atoi(argv[2]);
		cout << "filename readed from command line argument" << endl;
	}
	else {
		n = 5;
		fileName = "patients.txt";
		cout << "filename can not be readed from command line argument, inner file name will be used" << endl;
	}
	s.startSimulation(fileName, n);
	//cout << " in the main " << endl;
	//s.pq->pqPrint();


	//PriorityQueue* mewq = new PriorityQueue(*s.pq);
	//mewq->pqPrint();
	//Patient pati;
	//

	//for (int i = 0; i < 12; i++) {
	//	s.pq->pqDelete(pati);
	//	cout << "------";
	//	pati.printPatient();
	//	cout << "------" << endl;
	//	s.pq->pqPrint();
	//}

	//Patient * p1 = new Patient(1,20,1,10);
 //   Patient * p2 = new Patient(2,40,1,14);
	//Heap* hh = new Heap();
	////hh->heapInsert(*p1);
	////hh->heapInsert(*p2);
	//Heap* pp = new Heap(*hh);
	//pp->heapPrint();

	//Patient * p1 = new Patient(1,20,1,10);
 //   Patient * p2 = new Patient(2,40,1,14);
	//Patient * p3 = new Patient(3,10,1,6);
	//Patient* p4 = new Patient(4, 10, 1, 5);
	//Patient* p5 = new Patient(5, 20, 4, 10);
	//Patient* p6 = new Patient(6, 40, 7, 14);
	//Patient* p7 = new Patient(7, 20, 9, 10);
	//Patient* p8 = new Patient(8, 40, 11, 14);
	//Patient* p9 = new Patient(9, 10, 13, 6);
	//Patient* p10 = new Patient(10, 10, 14, 5);
	//Patient* p11 = new Patient(11, 20, 15, 10);
	//Patient* p12 = new Patient(12, 40, 17, 14);
	
	//p1->printPatient();



	//Patient* p1 = new Patient(1, 1, 1, 10);
	//Patient* p2 = new Patient(2, 2, 1, 14);
	//Patient* p3 = new Patient(3, 3, 1, 6);
	//Patient* p4 = new Patient(4, 4, 1, 5);
	//Patient* p5 = new Patient(5, 5, 4, 10);
	//Patient* p6 = new Patient(6, 6, 7, 14);
	//Patient* p7 = new Patient(7, 7, 9, 10);
	//Patient* p8 = new Patient(8, 8, 11, 14);
	//Patient* p9 = new Patient(9, 9, 13, 6);
	//Patient* p10 = new Patient(10, 10, 14, 5);
	//Patient* p11 = new Patient(11, 11, 15, 10);
	//Patient* p12 = new Patient(12, 12, 17, 14);







	//PriorityQueue* pp = new PriorityQueue();
	//pp->pqInsert(*p1);
	//pp->pqInsert(*p2);
	//pp->pqInsert(*p3);
	//pp->pqInsert(*p4);
	//pp->pqInsert(*p5);
	//pp->pqInsert(*p6);
	//pp->pqInsert(*p7);
	//pp->pqInsert(*p8);
	//pp->pqInsert(*p9);
	//pp->pqInsert(*p10);
	//pp->pqInsert(*p11);
	//pp->pqInsert(*p12);

	//pp->pqPrint();


	//pp->pqDelete(*p1);
	//pp->pqDelete(*p7);
	//pp->pqDelete(*p12);
	//cout << "---------" << endl;
	//pp->pqPrint();

	//hhh->heapInsert(*p1);
	//hhh->heapInsert(*p2);
	//hhh->heapInsert(*p3);
	//hhh->heapInsert(*p4);
	//hhh->heapInsert(*p5);
	//hhh->heapInsert(*p6);
	//hhh->heapInsert(*p7);
	//hhh->heapInsert(*p8);
	//hhh->heapInsert(*p9);
	//hhh->heapInsert(*p10);
	//hhh->heapInsert(*p11);
	//hhh->heapInsert(*p12);
	//hhh->heapPrint();
	return 0;
}

