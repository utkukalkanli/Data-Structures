#include "simulator.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>

using namespace std;


simulator::simulator()
{
	pq = new PriorityQueue();
	docs = new PriorityQueue();
	numberOfDoctors = 1;
	numberOfPatients = 0;
}




simulator::~simulator()
{
}

void simulator::startSimulation(string fileName,int maxAverage)
{
	string inputline;

	fstream file;
	file.open(fileName.c_str());
	int i = 1;
	numberOfPatients = 0;
	while (getline(file, inputline)) {
		if (i == 1) {
			// cout << inputline << endl;
			//numberOfPatients = stoi(inputline);
			numberOfPatients = atoi(inputline.c_str());
		}
		else {
			// cout << inputline << endl;
			string delimiter = " ";
			size_t pos = 0;
			string array[100];
			int k = 0;
			int numberOfWords = 0;
			string token;
			while ((pos = inputline.find(delimiter)) != string::npos) {
				// cout << "before tokening " << inputline << endl;
				token = inputline.substr(0, pos);
				array[k] = token;
				k++;
				numberOfWords++;
				inputline.erase(0, pos + delimiter.length());
			}
			string temp = array[3];
			//cout << "temp " << temp;
			temp = temp.substr(0, temp.length() - 1);
			//cout << "----- temp after substr =  " << temp << endl;
			// int id = stoi(array[0]);
			int id = atoi(array[0].c_str());
			//int hours = stoi(hours0);
			//int hours = atoi(hours0.c_str());
			int priority = atoi(array[1].c_str());
			// int priority = stoi(array[1]);
			//int arrival = stoi(array[2]);
			int arrival = atoi(array[2].c_str());
			if (temp == "") {
				temp = "14";  // WEIRD CASE PROGRAM DID NOT READ THE LAST İTEM OF THE LAST LİNE
			}
			// int treatment = stoi(temp);
			int treatment = atoi(temp.c_str());
			// cout << "id is " << id << " priority is " << priority << " arrival is " << arrival << " treatment is " << treatment << endl;

			Patient* p = new Patient(id, priority, arrival, treatment);
			pq->pqInsert(*p);


		}
		i++;
	}
	file.close();
	cout << "number of patients is " << numberOfPatients << endl;
	numberOfDoctors = findOptimumDoctors(maxAverage);

}

int simulator::findOptimumDoctors(int maxAverage)
{
	//int totalTime;
	//int calculatedAverage = maxAverage + 100;
 //   //	PriorityQueue temp;
	//while (calculatedAverage > maxAverage) {
	//	// REFRESH PQ İTEM;
	//	//temp = new PriorityQueue(this->pq);
	//    
	//	for (int j = numberOfPatients; j > 0; j--) {

	//		for (int i = 0; i < numberOfDoctors; i++) {

	//		}
	//	}
	//}
	Patient* doc1 = new Patient(0, 1, 1, 1);
	//Patient* doc2 = new Patient(1, 1, 1, 1);
	//Patient* doc3 = new Patient(2, 1, 1, 1);
	//Patient* doc4 = new Patient(3, 1, 1, 1);
	docs->pqInsert(*doc1);
	//docs->pqInsert(*doc2);
	//docs->pqInsert(*doc3);
	//docs->pqInsert(*doc4);
	PriorityQueue* temp = new PriorityQueue();

	Patient patient1;

	pq->pqPrint();

	cout << "--------" << endl;
	int totalTreatmentTime = 0;
	for (int i = 0; !pq->pqIsEmpty(); i++) {
			pq->pqDelete(patient1);
			cout << "Treating patient ";
			patient1.printPatient();
			totalTreatmentTime += patient1.getPatientTreatmentTime();
			temp->pqInsert(patient1);
	}
	
	cout << "--------" << endl;
	cout << "total treatment time " << totalTreatmentTime << endl;
	pq = temp;
	return 0;
}




