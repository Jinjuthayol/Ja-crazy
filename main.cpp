#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For sorting
using namespace std;

#include "doctor.h"
#include "patient.h"
#include "bst.h"
#include "urgency.h"

int main() {
    cout << "Welcome to the hospital management game!" << endl;
    cout << "Here are the instructions:" << endl;

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

    // Add doctors to a vector for easy access
    vector<Doctor> doctors = {Smith, Johnson, Williams, Jones, Brown,
                              Davis, Miller, Wilson, Moore, Taylor};

    cout << "Level 1 Fatal" << endl;
    cout << "Level 2 Moderate" << endl;
    cout << "Level 3 Low" << endl;
    cout << "Level 4 Minimal" << endl;

    // List of patients
    vector<Patient> patients = {
        {"Jean", 70, 'F', "Unconscious"}, {"KJ", 24, 'F', "Acute respiratory"}};/*,
        {"Xandra", 6, 'F', "Stomachache"}, {"Best", 17, 'M', "Shoulder dislocation"},
        {"New", 30, 'M', "Heart attack"}, {"Pat", 42, 'M', "Appendicitis"},
        {"Heart", 39, 'M', "Seasonal influenza"}, {"Hong", 54, 'F', "Hemiparesis"},
        {"Jill", 66, 'F', "Corneal Ulcer"}, {"Trin", 49, 'M', "Ankle sprain"}
    };*/

    // Binary Search Tree for storing urgency levels
    BST tree;
    int points = 0;

    // Process each patient
    for (const auto& patient : patients) {
        cout << "New Patient Alert: " << patient.name << " (" << patient.symptoms << ")" << endl;
        string doctorname;
        int urgencylevel;
        cout << "Which doctor should this patient go to?" << endl;
        cin >> doctorname;
        cout << "How severe do you think it is? (Level 1/2/3/4)" << endl;
        cin >> urgencylevel;



        // Find the doctor
        auto it = find_if(doctors.begin(), doctors.end(), [&](const Doctor& doc) {
            return doc.getName() == doctorname;
        });

        // If doctor exists and urgency level is valid
        if (it != doctors.end() && urgencylevel >= 1 && urgencylevel <= 4) {
            points++; // Increment points for correct match

            // Add patient to doctor's list
            it->addPatient(patient, urgencylevel);

            // Create urgency and insert into BST
            Urgency urgency(urgencylevel, doctorname, &(*it));
            tree.insert(&urgency);
        }
    }

    // Print all patients sorted by urgency for each doctor
    for (const auto& doctor : doctors) {
        if(!doctor.isEmpty())
        cout << "Patients for Doctor " << doctor.getName() << ":" << endl;
        doctor.printPatientsByUrgency();
    }

    // Display final points
    cout << "You saved " << points << " patients today!" << endl;

    return 0;
}
