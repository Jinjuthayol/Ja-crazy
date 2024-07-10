#ifndef doctor_h
#define doctor_h

#include <iostream>
#include <string>
#include <vector>
#include "patient.h"

using namespace std;

class Doctor {
private:
    string name;
    string specialization;
    vector<pair<int, Patient>> patientsByUrgency; // Using pair to store urgency level and patient

public:
    Doctor(string n, string spec) : name(n), specialization(spec) {}

    string getName() const {
        return name;
    }

    void addPatient(const Patient& patient, int urgencyLevel) {
        patientsByUrgency.push_back(make_pair(urgencyLevel, patient));
        // Sort patients by urgency level (ascending)
        sort(patientsByUrgency.begin(), patientsByUrgency.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
    }

    void printPatientsByUrgency() const {
        for (const auto& pair : patientsByUrgency) {
            cout << "Urgency Level " << pair.first << ": ";
            cout << "Patient: " << pair.second.name << " (" << pair.second.symptoms << ")" << endl;
        }
    }
    bool isEmpty() const {
        return patientsByUrgency.empty();
    }
};

#endif
