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

void scripting(const std::string& text, int delay = 50) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << std::endl;
}
int main() {
    cout << "Welcome to the hospital management mini game!" << endl;
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

    

    do {
        cout << "Main Menu:" << endl;
        cout << "1. Instructions" << endl;
        cout << "2. Start The Game" << endl;
        cout << "3. Exit Game" << endl;
        cout << "Enter your choice: ";
        cin >> menu;
        cout << endl;

        switch(menu) {
            case 1: {
                scripting("Here are the instructions:");
                cout<<endl;
                cout<<"Welcome once again! As the new hospital manager, your task is to ensure patients are attended to by the right doctors with the appropriate urgency."<<endl;

                // Print doctor list
                doctorList.printList();

                cout << "Level 1: Fatal" << endl;
                cout << "Level 2: Moderate" << endl;
                cout << "Level 3: Low" << endl;
                cout << "Level 4: Minimal" << endl;

                break;
            }
            
            case 2: {
                // Predefined list of patients
                Patient patients[] = {
                    {"Jean", 70, 'F', "Unconscious"}, {"KJ", 24, 'F', "Acute respiratory"}};/*,
                    {"Xandra", 6, 'F', "Stomachache"}, {"Best", 17, 'M', "Shoulder dislocation"},
                    {"New", 30, 'M', "Heart attack"}, {"Pat", 42, 'M', "Appendicitis"},
                    {"Heart", 39, 'M', "Seasonal influenza"}, {"Hong", 54, 'F', "Hemiparesis"},
                    {"Jill", 66, 'F', "Corneal Ulcer"}, {"Trin", 49, 'M', "Ankle sprain"}
                };
*/
                // Binary Search Tree for storing urgency levels
                BST tree;
                int points = 0;

                // Process each patient
                for (const auto& patient : patients) {
                    cout << "New Patient Alert: " << patient.name << " (" << patient.symptoms << ")" << endl;
                    string doctorName;
                    int urgencyLevel;

                    // Input doctor name
                    cout << "Which doctor should this patient go to?" << endl;
                    cin >> doctorName;

                    // Input urgency level
                    cout << "How severe do you think it is? (Level 1/2/3/4)" << endl;
                    cin >> urgencyLevel;

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
                }

                // Print all patients sorted by urgency for each doctor
                doctorList.printPatientsByUrgency();

                // Display final points
                cout << "You saved " << points << " patients today!" << endl;

                break;
            }

            case 3:
                cout << "Exiting the game. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
                break;
        }

    } while (menu != 3);

    return 0;
}
