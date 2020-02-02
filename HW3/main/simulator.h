#pragma once
#include "PriorityQueue.h"
class simulator
{
public:
	simulator();
	~simulator();
	void startSimulation(string fileName, int maxAverage);
	int findOptimumDoctors(int maxAverage);


	int numberOfDoctors;
	PriorityQueue* pq;
	PriorityQueue* docs;
	int numberOfPatients;
};

