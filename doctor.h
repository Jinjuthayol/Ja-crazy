#ifndef doctor_h
#define doctor_h

using namespace std;


class doctor{
    private: 
        string name;
        string specialization;
        // float shift;

    public:
        doctor();
        addPatient(const Patient& patient)
    
};
doctor::doctor(string n,string spec){
    name=n;
    specialization=spec;

}
 void patient::addPatient(const Patient& patient) {
        patients.push_back(patient);
}

