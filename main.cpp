#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "doctor.h"
#include "patient.h"
#include "bst.h"



class Doctor {
public:
    string name;
    vector<string> patients;

    Doctor(string n) : name(n) {}

    void addPatient(string patientName) {
        patients.push_back(patientName);
    }

    void printPatients() const {
        for (const string &patient : patients) {
            cout << patient << endl;
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


int main() {
    cout << "Welcome to hospital management game!" << endl;
    cout << "Here are the instructions" << endl;

    cout << "Emergency Room" << endl;
    cout << "Dr. Smith" << endl;
    cout << "Dr. Johnson" << endl;
    cout << "Obstetric-Gynecology" << endl;
    cout << "Dr. Williams" << endl;
    cout << "Dr. Jones" << endl;
    cout << "Pediatrics" << endl;
    cout << "Dr. Brown" << endl;
    cout << "Dr. Davis" << endl;
    cout << "Medicine" << endl;
    cout << "Dr. Miller" << endl;
    cout << "Dr. Wilson" << endl;
    cout << "Ophthalmology" << endl;
    cout << "Dr. Moore" << endl;
    cout << "Dr. Taylor" << endl;

    cout << "Level 1 Minimal" << endl;
    cout << "Level 2 Low" << endl;
    cout << "Level 3 Moderate" << endl;
    cout << "Level 4 Fatal" << endl;


    vector<Patient> patients = {{"John Doe", "Headache"}, {"Jane Smith", "Fever"}};

    for (const auto& patient : patients) {
        cout << "New Patient Alert: " << patient.name << " (" << patient.symptoms << ")" << endl;
        string doctorname;
        int urgencylevel;
        cout << "Which doctor should this patient go to?" << endl;
        cin >> doctorname;
        cout << "How severe do you think it is? (Level 1/2/3/4)" << endl;
        cin >> urgencylevel;

        // Assume we have some doctors defined
        Doctor doc(doctorname);
        doc.addPatient(patient.name);

        // Create urgency and insert into BST
        Urgency urgency(urgencylevel, doctorname, &doc);
        BST tree;
        tree.insert(&urgency);
    }

    // Print all patients sorted by urgency
    BST tree;
    tree.printPatientsByUrgency();

    return 0;
}

