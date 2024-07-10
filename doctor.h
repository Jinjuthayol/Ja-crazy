#ifndef doctor_h
#define doctor_h

#include <string>
#include <vector>
using namespace std;
#include "patient.h"


class Doctor {
private:
    string name;
    string specialization;
    vector<Patient> patients;

public:
    Doctor(string n) : name(n), specialization("") {}
    void addPatient(const Patient& patient) {
        patients.push_back(patient);
    }
    void printPatients() const {
        for (const auto& patient : patients) {
            cout << "Patient: " << patient.name << " (" << patient.symptoms << ")" << endl;
        }
    }
};
class Urgency {
public:
    int urgencyLevel;
    string doctorName;
    Doctor *doctor;

    Urgency(int level, string name, Doctor *doc) : urgencyLevel(level), doctorName(name), doctor(doc) {}
};

#endif 
