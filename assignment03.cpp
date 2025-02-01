#include <iostream>
#include <string>
using namespace std;

class Patient {
protected:
    string name;
    int age;
    string medicalHistory;
public:
    Patient(string name, int age, string mediHis) : name(name), age(age), medicalHistory(mediHis) {}
    virtual void viewDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Medical History: " << medicalHistory << endl;
    }
    virtual void scheduleAppointment() = 0;  // Pure virtual function
    string getName() { return name; }
    virtual ~Patient() {}
};

class InPatient : public Patient {
    string roomNumber;
public:
    InPatient(string n, int a, string mh, string room) : Patient(n, a, mh), roomNumber(room) {}
    void viewDetails() override {
        Patient::viewDetails();
        cout << "Room Number: " << roomNumber << endl;
    }
    virtual void scheduleAppointment(){}
};

class OutPatient : public Patient {
    string appointmentTime;
public:
    OutPatient(string n, int a, string mh, string time) : Patient(n, a, mh), appointmentTime(time) {}
    void viewDetails() override {
        Patient::viewDetails();
        cout << "Appointment Time: " << appointmentTime << endl;
    }
    virtual void scheduleAppointment(){}
};

class Doctor {
    string name;
    string specialization;
    string* appointments;
    int appointmentCount;
public:
    Doctor(string n, string spec) : name(n), specialization(spec), appointmentCount(0) {
        appointments = new string[100];  // Assuming maximum 100 appointments for simplicity
    }
    ~Doctor() {
        delete[] appointments;
    }
    void viewAppointments() {
        cout << "Appointments for Dr. " << name << " (" << specialization << "):" << endl;
        for (int i = 0; i < appointmentCount; i++) {
            cout << " - " << appointments[i] << endl;
        }
    }
    void addAppointment(const string &appointment) {
        if (appointmentCount < 100) {
            for (int i = 0; i < appointmentCount; i++) {
                if (appointments[i] == appointment) {
                    throw runtime_error("Scheduling conflict: Appointment already exists at this time.");
                }
            }
            appointments[appointmentCount++] = appointment;
        } else {
            throw runtime_error("No more appointments can be scheduled.");
        }
    }
    void showDetails(){
        cout << "\tDoctor Name: " << name << endl;
        cout << "\tSpecialization: " << specialization << "\n" << endl;
    }
    string getName() { return name; }
};

class Appointment {
    string date;
    Patient* patient;
    Doctor* doctor;
public:
    Appointment(string d, Patient* p, Doctor* dctr) : date(d), patient(p), doctor(dctr) {}
    void schedule() {
        try {
            cout << "Scheduling appointment on " << date << " for " << patient->getName() << " with Dr. " << doctor->getName() << endl;
            doctor->addAppointment(date);
            cout << "Appointment scheduled successfully." << endl;
        } catch (const runtime_error& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    void cancel() {
        cout << "Appointment on " << date << " cancelled." << endl;
    }
};

class Billing {
    Patient* patient;
    float amount;
public:
    Billing(Patient* p, float amt) : patient(p), amount(amt) {}
    void generateInvoice() {
        if (!patient) {
            throw runtime_error("Invalid operation: Patient does not exist.");
        }
        cout << "Generating invoice for " << patient->getName() << endl;
        cout << "Total amount due: $" << amount << endl;
    }
};

void showMenu() {
    cout << "***** Welcome to LifeCare Hospital *****" << endl;
    cout << "1. View available doctors" << endl;
    cout << "2. Book appointment" << endl;
    cout << "3. View doctor appointments" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Doctor* doctors[7];
    doctors[0] = new Doctor("Dr. Rahul Kumar", "Dermatologist");
    doctors[1] = new Doctor("Dr. Ankit Chauhan", "Cardiologist");
    doctors[2] = new Doctor("Dr. Priya Sharma", "Neurologist");
    doctors[3] = new Doctor("Dr. Rohan Mehta", "Orthopedic Surgeon");
    doctors[4] = new Doctor("Dr. Sneha Kapoor", "Pediatrician");
    doctors[5] = new Doctor("Dr. Amit Singh", "General Practitioner");
    doctors[6] = new Doctor("Dr. Neha Gupta", "Gynecologist");

    Patient* patient = nullptr;
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "** Available doctors **" << endl;
                for (int i = 0; i < 7; i++) {
                    cout <<"Doctor " << i + 1 <<endl;
                    doctors[i]->showDetails();
                }
                break;
            }
            case 2:{
                int pType;
                string name, sym, temp;
                int age;
                cout << "\tSelect the patient type" << endl;
                cout << "\tPress 1 for InPatient" << endl;
                cout << "\tPress 2 for OutPatient" << endl;
                cin >> pType;
                cout << "\tEnter the name: ";
                cin >> name;
                cout << "\tEnter the Disease: ";
                cin >> sym;
                cout << "\tEnter the age: ";
                cin >> age;
                if (pType == 1) {
                    cout << "\tEnter the Room No: ";
                    cin >> temp;
                    patient = new InPatient(name, age, sym, temp);
                } else if (pType == 2) {
                    cout<<"Enter the time:";
                    cin >> temp;
                    patient = new OutPatient(name, age, sym, temp);
                }
                cout << "Patient registered successfully." << endl;
                patient->viewDetails();
                if (!patient) {
                    cout << "No patient registered. Please register a patient first." << endl;
                    break;
                }
                int prefer;
                string date;
                cout << "** Available doctors **" << endl;
                for (int i = 0; i < 7; i++) {
                    cout << "\tDoctor " << i + 1 <<endl;
                    doctors[i]->showDetails();
                }
                cout << "\tEnter your Doctor Preference: ";
                cin >> prefer;
                if (prefer < 1 || prefer > 7) {
                    cout << "Invalid doctor selection." << endl;
                    break;
                }
                cout << "\tEnter the Appointment Date (DD-MM-YYYY): ";
                cin >> date;
                try {
                    Appointment app(date, patient, doctors[prefer - 1]);
                    app.schedule();
                } catch (const runtime_error& e) {
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            }
            case 3: {
                int prefer;
                cout << "\tEnter your Doctor Preference: ";
                cin >> prefer;
                if (prefer < 1 || prefer > 7) {
                    cout << "Invalid doctor selection." << endl;
                    break;
                }
                doctors[prefer - 1]->viewAppointments();
                break;
            }
            case 5:
                cout << "Thank you for using LifeCare Hospital Management System." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    for (int i = 0; i < 7; i++) {
        delete doctors[i];
    }
    delete patient;

    return 0;
}
