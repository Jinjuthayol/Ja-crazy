#include <iostream>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>
#include "doctor.h"
#include "bst.h"
#include "urgency.h"
#include "patient.h"

using namespace std;

void scripting(const string& text, int delay = 50) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    //cout << std::endl;
}
void pressentertocontinue() {
    //cout << "Press Enter to continue..." << std::flush;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int main() {
    int menu;
    LL doctorList;

    // Create Doctor objects
    Doctor Smith("Smith", "Emergency Room");
    Doctor Johnson("Johnson", "Emergency Room");
    Doctor Williams("Williams", "Obstetric-Gynecology");
    Doctor Jones("Jones", "Obstetric-Gynecology");
    Doctor Brown("Brown", "Pediatrics");
    Doctor Davis("Davis", "Pediatrics");
    Doctor Miller("Miller", "Medicine");
    Doctor Wilson("Wilson", "Medicine");
    Doctor Moore("Moore", "Ophthalmology");
    Doctor Taylor("Taylor", "Ophthalmology");

    // Linked list to store doctors
    doctorList.addDoctor(&Smith);
    doctorList.addDoctor(&Johnson);
    doctorList.addDoctor(&Williams);
    doctorList.addDoctor(&Jones);
    doctorList.addDoctor(&Brown);
    doctorList.addDoctor(&Davis);
    doctorList.addDoctor(&Miller);
    doctorList.addDoctor(&Wilson);
    doctorList.addDoctor(&Moore);
    doctorList.addDoctor(&Taylor);

 
                scripting("Welcome to the hospital management mini game!\nAs the new hospital manager, your task is to ensure patients are attended to by the right doctors with the appropriate urgency.\n");
                scripting("ARE YOU READY??");
                pressentertocontinue();
                scripting("First, Let's review the doctors information, they are the superheroes of our hospital!\n");
                
                // Print doctor list
                doctorList.printList();
                pressentertocontinue();

                scripting("\nAnd these are the urgency level:\n");

                cout << "Level 1: Fatal (Immediate attention needed)" << endl;
                cout << "Level 2: Moderate (Needs attention soon)" << endl;
                cout << "Level 3: Low (Can wait for a bit)" << endl;
                cout << "Level 4: Minimal (Routine check-up)\n" << endl;

                pressentertocontinue();
                scripting("Patients will arrive with symptoms and you should decide which doctor \nthey should see according to their specialization and the urgency of their condition.\n");

                scripting("Now you are ready to start the game!!");
                cout<<endl;
                pressentertocontinue();

                // Predefined list of patients
                Patient patients[] = {
                    {"Jean", 70, 'F', "Cholecystitis"}, //2
                    {"KJ", 48, 'F', "Diabetic Ketoacidosis"}};/*,//2
                    {"Xandra", 6, 'F', "Bronchiolitis"},//3
                    {"Best", 57, 'M', "Retinal Detachment"},//1
                    {"New", 62, 'M', "Heart attack"}, //1
                    {"Pat", 42, 'M', "Appendicitis"}, //1
                    {"Heart", 3, 'M', "Acute Otitis Media"}, //4
                    {"Hong", 30, 'F', "Ectopic Pregnancy"},//1
                    {"Jill", 66, 'F', "Ovarian Cyst"}, //3
                    {"Trin", 19, 'M', "Conjunctivitis"} //4
                };*/

                // Binary Search Tree for storing urgency levels
                BST tree;
                int points = 0;

                // Process each patient
                for (const auto& patient : patients) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
                    cout << "New Patient Alert!"<<endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    cout<<patient.name << ", "<< patient.age << " years old, " << patient.sex << ",";
                    cout<<" comes to the hospital with " << patient.symptoms <<" symptoms";
                    pressentertocontinue();
                    string doctorName;
                    int urgencyLevel;

                    // Input doctor name
                    pressentertocontinue();
                    cout<<endl;
                    scripting("Which doctor should this patient go to?\n");
                    cin >> doctorName;

                    // Input urgency level
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    cout<<endl;
                    scripting("How severe do you think it is? (Level 1/2/3/4)?\n");
                    cin >> urgencyLevel;
                    cout<<endl;

                    bool correctanswer = false;

                    // Example predefined answers
                    if (patient.name == "Jean" && (doctorName == "Smith" || doctorName == "Johnson") && urgencyLevel == 2) {
                        correctanswer = true;
                    } else if (patient.name == "KJ" && (doctorName == "Miller" || doctorName == "Wilson") && urgencyLevel == 2) {
                        correctanswer = true;
                    } else if (patient.name == "Xandra" && (doctorName == "Brown" || doctorName == "Davis") && urgencyLevel == 3) {
                        correctanswer = true;
                    } else if (patient.name == "Best" && (doctorName == "Moore" || doctorName == "Taylor") && urgencyLevel == 1) {
                        correctanswer = true;
                    } else if (patient.name == "New" && (doctorName == "Miller" || doctorName == "Wilson") && urgencyLevel == 1) {
                        correctanswer = true;
                    } else if (patient.name == "Pat" && (doctorName == "Smith" || doctorName == "Johnson") && urgencyLevel == 1) {
                        correctanswer = true;
                    } else if (patient.name == "Heart" && (doctorName == "Brown" || doctorName == "Davis") && urgencyLevel == 4) {
                        correctanswer = true;
                    } else if (patient.name == "Hong" && (doctorName == "Williams" || doctorName == "Jones") && urgencyLevel == 1) {
                        correctanswer = true;
                    } else if (patient.name == "Jill" && (doctorName == "Williams" || doctorName == "Jones") && urgencyLevel == 3) {
                        correctanswer = true;
                    } else if (patient.name == "Trin" && (doctorName == "Moore" || doctorName == "Taylor") && urgencyLevel == 4) {
                        correctanswer = true;
                    }

                    Doctor* selectedDoctor = doctorList.findDoctor(doctorName);

                    // If doctor exists
                    if (selectedDoctor) {
                        // Add patient to doctor's list
                        selectedDoctor->addPatient(patient, urgencyLevel);

                        // Create urgency and insert into BST
                        Urgency urgency(urgencyLevel, doctorName, selectedDoctor);
                        tree.insert(&urgency);

                        if (correctanswer) {
                            points++; // Increment points for correct match
                        }
                    }
                    else scripting("This doctor couldn't be found in the record this hospital.\n");

                    scripting("Let's check the status of our patients so far.\nLooking at the list(s) of doctors patients\n");
                    cout<<endl;

                    // Print all patients sorted by urgency for each doctor
                    doctorList.printPatientsByUrgency();
                    if(correctanswer) scripting("You're doing an excellent job, Hospital Manager! Keep going and save more lives.\n");
                    cout<<endl;
                    pressentertocontinue();

                }

                
                // Display final points
                scripting("You saved ");
                if (points==0) scripting("no patient today, unfortunately.\n");
                else {
                    cout<<points;
                    if (points==1) scripting(" patient today!\n");
                    else scripting(" patient today!\n");
                }

            scripting("Goodbye, Hospital Manager! Thanks for all your hard work. The hospital is in better shape because of you!\n");
  

    return 0;
}

