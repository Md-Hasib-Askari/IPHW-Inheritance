#include <iostream>
using namespace std;

class Student {
    string StudentName;
    string StudentID;
    string StudentDept;
    string StudentAddress;
    int Semester;
    int Credits;
    int StudentAge;
public:
    double CGPA;
    double fee;
    Student(){}
    void setStudent(string name, string id, string dept, string address, int semester, int credit, double cgpa, int age){
        StudentName = name;
        StudentID = id;
        StudentDept = dept;
        StudentAddress = address;
        Semester = semester;
        Credits = credit;
        CGPA = cgpa;
        StudentAge = age;
    }
    void getInfo() {
        cout << "Student Name: " << StudentName << "\n";
        cout << "Student ID: " << StudentID << "\n";
        cout << "Student Department: " << StudentDept << "\n";
        cout << "Student Address: " << StudentAddress << "\n";
        cout << "Semester: " << Semester << "\n";
        cout << "Credits: " << Credits << "\n";
        cout << "CGPA: " << CGPA << "\n";
        cout << "Student Age: " << StudentAge << "\n";
    }
    void TuitionFee() {
        fee = Credits * 5500.0;
        cout << "Tuition Fee: " << fee << "\n";
    }
};

class ScholarshipStudent : virtual public Student {
    double ScholarshipAmount;
public:
    ScholarshipStudent(){}
    void Scholarship() {
        ScholarshipAmount = fee * 0.5;
        cout << "Scholarship Amount: " << ScholarshipAmount << "\n";
        cout << "Tuition Fee After Scholarship: " << fee - ScholarshipAmount << "\n";
    }
};

class WaiverStudent : virtual public Student {
    double WaiverAmount;
public:
    WaiverStudent() {}
    void Waiver() {
        WaiverAmount = fee * 0.25;
        cout << "Waiver Amount: " << WaiverAmount << "\n";
        cout << "Current Fee: " << fee - WaiverAmount << "\n";
    }
};

int main() {
    ScholarshipStudent s1;
    s1.setStudent("Rakib", "201-15-12345", "CSE", "Dhaka", 8, 120, 3.5, 22);
    s1.getInfo();
    s1.TuitionFee();
    s1.Scholarship();
    cout << endl;
    WaiverStudent s2;
    s2.setStudent("Sakib", "201-15-22245", "EEE", "Dhaka", 12, 148, 3.25, 21);
    s2.getInfo();
    s2.TuitionFee();
    s2.Waiver();
}
