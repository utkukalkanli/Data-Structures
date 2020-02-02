#pragma once
class Patient
{
public:
	Patient();
	Patient(const Patient& toCopy);
	Patient(int id, int priority, int arrivalTime, int treatmentTime);
	~Patient();
	int getPatientId();
	int getPatientPriority();
	int getPatientArrivalTime();
	int getPatientTreatmentTime();
	void operator=(const Patient&);
	void printPatient();

private:
	int id;
	int priority;
	int arrivalTime;
	int treatmentTime;
};

