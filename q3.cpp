#include <iostream>
using namespace std;
class Patient {
protected:
    string Patient_Name;
    string Patient_ID;
    string pcr;
    float charge = 1500;
public:
    Patient() {}
    Patient(string pcr) {
        this->pcr = pcr;
        if(pcr == "positive") {
            cout << "covid positive";
        } else {
            cout << "covid negative";
        }
        cout << endl;
    }
    void GetPatientDetails(string name, string id) {
        this->Patient_Name = name;
        this->Patient_ID = id;
    }
    void ShowPatientDetails() {
        cout << "Patient Name: " << Patient_Name << "\n";
        cout << "Patient ID: " << Patient_ID << "\n";
        cout << "PCR: " << pcr << "\n";
        cout << "Charge: " << charge << "\n";
    }
};

class CovidPatient : public Patient {
public:
    CovidPatient() {}
    CovidPatient(string pcr) : Patient(pcr) {
        if (pcr == "positive") {
            Patient::charge -= Patient::charge * 0.15;
            cout << "You got 15% discount!\n";
        } else {
            cout << "No Discount!\n";
        }
    }
};

class NormalPatient : public CovidPatient {
public:
    NormalPatient() {}
    NormalPatient(string pcr) : CovidPatient(pcr) {}
};

int main() {
    NormalPatient obj1("negative");
    obj1.GetPatientDetails("Ali", "AB1234");
    obj1.ShowPatientDetails();

    cout << endl;
    NormalPatient obj2("positive");
    obj2.GetPatientDetails("Rahim", "AB5432");
    obj2.ShowPatientDetails();

}
