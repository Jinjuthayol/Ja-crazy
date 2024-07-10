#ifndef urgency_h
#define urgency_h

#include <string>
#include "doctor.h"

using namespace std;

class Urgency {
public:
    int urgencyLevel;
    string doctorName;
    Doctor* doctor;

    Urgency(int level, string name, Doctor* doc) : urgencyLevel(level), doctorName(name), doctor(doc) {}
};

#endif
