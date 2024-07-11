#ifndef doctor_h
#define doctor_h

#include <iostream>
#include <iomanip>
#include <string>
#include "patient.h"

using namespace std;

class Doctor {
private:
    string name;
    string specialization;
    struct PatientNode {
        Patient patient;
        int urgencyLevel;
        PatientNode* next;

        PatientNode(const Patient& p, int level) : patient(p), urgencyLevel(level), next(nullptr) {}
    };
    PatientNode* head;

public:
    Doctor(string n, string spec) : name(n), specialization(spec), head(nullptr) {}

    string getName() const {
        return name;
    }

    string getSpecialization() const {
        return specialization;
    }

    void addPatient(const Patient& patient, int urgencyLevel) {
        PatientNode* newNode = new PatientNode(patient, urgencyLevel);
        if (!head || urgencyLevel < head->urgencyLevel) {
            newNode->next = head;
            head = newNode;
        } else {
            PatientNode* current = head;
            while (current->next && current->next->urgencyLevel >= urgencyLevel) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void printPatientsByUrgency() const {
        PatientNode* current = head;
        while (current) {
            cout << setfill(' ')<<setw(16)<<current->urgencyLevel;
            cout << current->patient.name << " (" << current->patient.symptoms << ")" << endl;
            current = current->next;
        }
    }

    bool isEmpty() const {
        return !head;
    }

    Doctor* getNext() const {
        return nullptr; // Implement if needed
    }

    void setNext(Doctor* d) {
        // Implement if needed
    }

    ~Doctor() {
        while (head) {
            PatientNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class LL {
private:
    struct Node {
        Doctor* doctor;
        Node* next;
        Node(Doctor* d) : doctor(d), next(nullptr) {}
    };

    Node* head;

public:
    LL() : head(nullptr) {}

    void addDoctor(Doctor* doctor) {
        Node* newNode = new Node(doctor);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList() const {
    Node* temp = head;
    cout << left << setw(20) << "Name" << " " << left << setw(30) << "Specialization" << endl;
    cout << string(51, '-') << endl; 

    while (temp) {
        cout << left << setw(20) << temp->doctor->getName()
             << " " << left << setw(20) << temp->doctor->getSpecialization() << endl;
        temp = temp->next;
    }
}

    Doctor* findDoctor(const string& doctorName) const {
        Node* temp = head;
        while (temp) {
            if (temp->doctor->getName() == doctorName) {
                return temp->doctor;
            }
            temp = temp->next;
        }
        return nullptr; // Doctor not found
    }

    bool hasPatients() const {
        Node* temp = head;
        while (temp) {
            if (!temp->doctor->isEmpty()) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void printPatientsByUrgency() const {
        Node* temp = head;
        while (temp) {
            if (!temp->doctor->isEmpty()) {
                cout << "Doctor " << temp->doctor->getName() << "'s patients chart:" << endl;
                cout << left << setw(15) << "Urgency Level" << " " << left << "Name (Symptoms)" << endl;
                cout << string(40, '-') << endl;
                temp->doctor->printPatientsByUrgency();
                cout << endl;
            }
            temp = temp->next;
        }
    }

    ~LL() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif
