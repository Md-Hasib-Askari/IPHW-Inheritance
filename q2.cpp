#include <iostream>
#include <iomanip>

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
        cout << fixed << setprecision(2);
        cout << "Name: " << Name << endl;
        cout << "Occupation: " << Occupation << endl;
        cout << "Phone Number: " << PhoneNumber << endl;
        cout << "Account Number: " << Salary_Account_Number << endl;
        cout << "Salary: " << SalaryBalance << endl;
    }

};
class Utility : public Account {
    double ElectricityBill;
    double GasBill;
    double Transportation;
    double food;
    double HouseRent;
public:
    Utility() {}
    void setUtility(double electricity, double gas, double transport, double fd, double rent) {
        this->ElectricityBill = electricity;
        this->GasBill = gas;
        this->Transportation = transport;
        this->food = fd;
        this->HouseRent = rent;
    }
    void PrintUtility() {
        cout << fixed << setprecision(2);
        cout << "Electricity Bill: " << ElectricityBill << endl;
        cout << "Gas Bill: " << GasBill << endl;
        cout << "Transportation: " << Transportation << endl;
        cout << "Food: " << food << endl;
        cout << "House Rent: " << HouseRent << endl;
    }
    void payment() {
        SalaryBalance = SalaryBalance - (ElectricityBill + GasBill + Transportation + food + HouseRent);
        cout << "Salary Balance: " << SalaryBalance << endl;
    }

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
    void PrintExtraExpense() {
        cout << fixed << setprecision(2);
        cout << "Shopping: " << Shopping << endl;
        cout << "Vacation: " << Vacation << endl;
        cout << "Charity: " << Charity << endl;
    }
    void ExtraPayment() {
        double deduction = Shopping+Vacation+Charity;
        SalaryBalance = SalaryBalance - deduction;
    }

};


int main() {
    Utility obj1;
    ExtraExpense obj2;
    obj1.Get_Parent_Salary_Account_info("Md. Shohag", "Student", "01700000000", "101.23a.4b");
    obj1.PrintSalaryinfo();
    obj1.setUtility(1000, 500, 1000, 2000, 5000);
    obj1.PrintUtility();
    obj1.payment();
    obj2.setExtraExpence(1000, 5000, 1000);
    obj2.PrintExtraExpense();
    obj2.ExtraPayment();
    obj1.PrintSalaryinfo();
    return 0;
}
