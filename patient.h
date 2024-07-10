#ifndef patient_h
#define patient_h

using namespace std;


class patient{
    private: 
        string name;
        char sex;
        int age;
        char medCon;
        // char medHis;
        // string alergies;
        // char insurance;

    public:
        //bool alive();
        string symptoms();
        patient(string name,string symptoms);
        
};
patient:: patient(string n, int a, char s, string symp){
    name=n; 
    age=a;
    sex=s;
    symptoms=symp; 
}



