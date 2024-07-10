#ifndef patient_h
#define patient_h

#include <string>
using namespace std;

class Patient {
public:
    string name;
    int age;
    char sex;
    string symptoms;
    Patient(string n, int a,char sx,string s): name(n), age(a), sex(sx), symptoms(s) {}
};

#endif 
