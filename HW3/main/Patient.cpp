#include "Patient.h"
#include <iostream>

using namespace std;

Patient::Patient()
{
}

Patient::Patient(const Patient& toCopy)
{
	this->id = toCopy.id;
	this->priority = toCopy.priority;
	this->arrivalTime = toCopy.arrivalTime;
	this->treatmentTime = toCopy.treatmentTime;
}

Patient::Patient(int id, int priority, int arrivalTime, int treatmentTime)
{
	this->id = id;
	this->priority = priority;
	this->arrivalTime = arrivalTime;
	this->treatmentTime = treatmentTime;
}




Patient::~Patient()
{
}

int Patient::getPatientId()
{
	return id;
}

int Patient::getPatientPriority()
{
	return priority;
}

int Patient::getPatientArrivalTime()
{
	return arrivalTime;
}

int Patient::getPatientTreatmentTime()
{
	return treatmentTime;
}

void Patient::operator=(const Patient& baby)
{
	id = baby.id;
	priority = baby.priority;
	arrivalTime = baby.arrivalTime;
	treatmentTime = baby.treatmentTime;
}

void Patient::printPatient()
{
	// cout << "id: " << id << " priority: " << priority << " arrival time: " << arrivalTime << " treatment time: " << treatmentTime << endl;
	cout << "" << id << " " << priority << " " << arrivalTime << " " << treatmentTime << endl;
}
