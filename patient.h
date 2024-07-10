#ifndef patient_h
#define patient_h

#include <string>
using namespace std;

class Patient {
public:
    string name;
    string symptoms;
    Patient(string n, string s) : name(n), symptoms(s) {}
};

#endif 
