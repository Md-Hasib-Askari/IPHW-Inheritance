#include <iostream>
using namespace std;

class Account{
protected:
    double SalaryBalance = 5000000;
    string Name;
    string Occupation;
    char *PhoneNumber;
    string Salary_Account_Number = "101.23a.4b";
public:
    Account() {}
    ~Account() {}
    void Get_Parent_Salary_Account_info(string nm, string occ, char phn[], string acNo) {
        this->Name = nm;
        this->Occupation = occ;
        this->PhoneNumber = &phn[0];
        this->Salary_Account_Number = acNo;
    }
    void PrintSalaryinfo() {
        cout << "Name: " << Name << endl;
        cout << "Occupation: " << Occupation << endl;
        cout << "Phone Number: " << PhoneNumber << endl;
        cout << "Account Number: " << Salary_Account_Number << endl;
        cout << "Salary: " << SalaryBalance << endl;
    }

};
class Utility : public Account {


};
class ExtraExpense : public Account {
    double Shopping;
    double Vacation;
    double Charity;
public:
    ExtraExpense() {}
    ExtraExpense(double shop, double vac, double charity) {
        this->Shopping = shop;
        this->Vacation = vac;
        this->Charity = charity;
    }
    void setExtraExpence(double shop, double vac, double charity) {
        this->Shopping = shop;
        this->Vacation = vac;
        this->Charity = charity;
    }
    Void ExtraPayment() {
        double deduction = Shopping+Vacation+Charity;
    }

};


int main() {

}
