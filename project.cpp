#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

// Base Class
class Person {
public:
    string name;
    int age;
    string gender;

    void inputBasicInfo() {
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
    }

    void displayBasicInfo() const {
        cout << left << setw(20) << name
             << setw(5) << age
             << setw(10) << gender;
    }
};

// Doctor Class
class Doctor : public Person {
    string specialty, availability;
public:
    void inputAndSave() {
        inputBasicInfo();
        cin.ignore();
        cout << "Enter Specialty: ";
        getline(cin, specialty);
        cout << "Enter Availability (e.g., Mon-Fri 9AM-5PM): ";
        getline(cin, availability);

        ofstream fout("doctors.txt", ios::app);
        fout << name << "," << age << "," << gender << ","
             << specialty << "," << availability << endl;
        fout.close();
    }

    void displayFromLine(const string& line) {
        stringstream ss(line);
        getline(ss, name, ',');
        ss >> age;
        ss.ignore();
        getline(ss, gender, ',');
        getline(ss, specialty, ',');
        getline(ss, availability);

        displayBasicInfo();
        cout << setw(20) << specialty << setw(20) << availability << endl;
    }

    static void showAll() {
        ifstream fin("doctors.txt");
        string line;
        cout << "\n--- Doctor List ---\n";
        cout << left << setw(20) << "Name" << setw(5) << "Age" << setw(10) << "Gender"
             << setw(20) << "Specialty" << setw(20) << "Availability" << endl;

        Doctor d;
        while (getline(fin, line)) {
            d.displayFromLine(line);
        }
        fin.close();
    }
};

// Patient Class
class Patient : public Person {
    string disease, doctorName;
public:
    void inputAndSave() {
        inputBasicInfo();
        cin.ignore();
        cout << "Enter Disease/Symptoms: ";
        getline(cin, disease);
        cout << "Enter Assigned Doctor: ";
        getline(cin, doctorName);

        ofstream fout("patients.txt", ios::app);
        fout << name << "," << age << "," << gender << ","
             << disease << "," << doctorName << endl;
        fout.close();
    }

    void displayFromLine(const string& line) {
        stringstream ss(line);
        getline(ss, name, ',');
        ss >> age;
        ss.ignore();
        getline(ss, gender, ',');
        getline(ss, disease, ',');
        getline(ss, doctorName);

        displayBasicInfo();
        cout << setw(20) << disease << setw(20) << doctorName << endl;
    }

    static void showAll() {
        ifstream fin("patients.txt");
        string line;
        cout << "\n--- Patient Records ---\n";
        cout << left << setw(20) << "Name" << setw(5) << "Age" << setw(10) << "Gender"
             << setw(20) << "Disease" << setw(20) << "Doctor" << endl;

        Patient p;
        while (getline(fin, line)) {
            p.displayFromLine(line);
        }
        fin.close();
    }
};

// Staff Class
class Staff : public Person {
    string role;
public:
    void inputAndSave() {
        inputBasicInfo();
        cin.ignore();
        cout << "Enter Role (e.g., Nurse, Receptionist): ";
        getline(cin, role);

        ofstream fout("staff.txt", ios::app);
        fout << name << "," << age << "," << gender << ","
             << role << endl;
        fout.close();
    }

    void displayFromLine(const string& line) {
        stringstream ss(line);
        getline(ss, name, ',');
        ss >> age;
        ss.ignore();
        getline(ss, gender, ',');
        getline(ss, role);

        displayBasicInfo();
        cout << setw(20) << role << endl;
    }

    static void showAll() {
        ifstream fin("staff.txt");
        string line;
        cout << "\n--- Hospital Staff ---\n";
        cout << left << setw(20) << "Name" << setw(5) << "Age" << setw(10) << "Gender"
             << setw(20) << "Role" << endl;

        Staff s;
        while (getline(fin, line)) {
            s.displayFromLine(line);
        }
        fin.close();
    }
};

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n====== Hospital Management System ======\n";
        cout << "1. Add New Doctor\n";
        cout << "2. Show All Doctors\n";
        cout << "3. Add New Patient\n";
        cout << "4. Show All Patients\n";
        cout << "5. Add New Staff\n";
        cout << "6. Show All Staff\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Doctor d;
                d.inputAndSave();
                break;
            }
            case 2:
                Doctor::showAll();
                break;
            case 3: {
                Patient p;
                p.inputAndSave();
                break;
            }
            case 4:
                Patient::showAll();
                break;
            case 5: {
                Staff s;
                s.inputAndSave();
                break;
            }
            case 6:
                Staff::showAll();
                break;
            case 7:
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}