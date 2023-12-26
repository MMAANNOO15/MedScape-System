#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Patient {
private:
    string email;
    string password;
    string diagnosis;
    string firstName;
    string lastName;
    string gender;
    string dateOfBirth;

public:
    Patient(string e, string p, string d, string fn, string ln, string g, string dob)
        : email(e), password(p), diagnosis(d), firstName(fn), lastName(ln), gender(g), dateOfBirth(dob) {}

    string getEmail() const {
        return email;
    }

    string getPassword() const {
        return password;
    }

    string getDiagnosis() const {
        return diagnosis;
    }

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    string getGender() const {
        return gender;
    }

    string getDateOfBirth() const {
        return dateOfBirth;
    }
};

class Hospital {
private:
    vector<Patient> patients;

public:
    void admitPatient(const Patient& p) {
        patients.push_back(p);
        cout << "Patient admitted to the hospital." << endl;
    }

    void dischargePatient(const Patient& p) {
        for (auto it = patients.begin(); it != patients.end(); ++it) {
            if (it->getEmail() == p.getEmail()) {
                patients.erase(it);
                cout << "Patient discharged from the hospital." << endl;
                return;
            }
        }
        cout << "Patient not found." << endl;
    }

    void displayPatients() const {
        cout << "Patients currently admitted:" << endl;
        for (const auto& patient : patients) {
            cout << "Name: " << patient.getFirstName() << " " << patient.getLastName() 
                 << ", Email: " << patient.getEmail() << ", Gender: " << patient.getGender() 
                 << ", Date of Birth: " << patient.getDateOfBirth() << ", Diagnosis: " << patient.getDiagnosis() << endl;
        }
        cout << endl;
    }
};

int main() {
    Hospital hospital;

    int choice;
    do {
        cout << "Hospital Management System" << endl;
        cout << "1. Admit Patient" << endl;
        cout << "2. Discharge Patient" << endl;
        cout << "3. Display Admitted Patients" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string email, password, diagnosis, firstName, lastName, gender, dateOfBirth;
                cout << "Enter patient email: ";
                cin.ignore();
                getline(cin, email);
                cout << "Enter patient password: ";
                getline(cin, password);
                cout << "Enter patient first name: ";
                getline(cin, firstName);
                cout << "Enter patient last name: ";
                getline(cin, lastName);
                cout << "Enter patient gender: ";
                getline(cin, gender);
                cout << "Enter patient date of birth (DD/MM/YYYY): ";
                getline(cin, dateOfBirth);
                cout << "Enter diagnosis: ";
                getline(cin, diagnosis);
                Patient newPatient(email, password, diagnosis, firstName, lastName, gender, dateOfBirth);
                hospital.admitPatient(newPatient);
                break;
            }
            case 2: {
                string email;
                cout << "Enter patient email to discharge: ";
                cin.ignore();
                getline(cin, email);
                Patient patientToDischarge(email, "", "", "", "", "", "");
                hospital.dischargePatient(patientToDischarge);
                break;
            }
            case 3:
                hospital.displayPatients();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}