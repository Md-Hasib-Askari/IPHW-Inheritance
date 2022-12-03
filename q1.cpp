#include <iostream>
#include <cstring>
using namespace std;

class ParentSalaryAccount {
protected:
    string Name;
    string Occupation;
    char *PhoneNumber;
    string SalaryAccountNumber = "101.23a.4b";
    double SalaryBalance = 205000;
public:
    ParentSalaryAccount() {}
    ~ParentSalaryAccount() {
        cout << Name << ", Your current Salary balance is " << SalaryBalance << endl;
    }
    void Get_Parent_Salary_Account_Info(string nm, string occ, char phnNum[], string AcNo, double balance) {
        this->Name = nm;
        this->Occupation = occ;
        this->PhoneNumber = phnNum;
        this->SalaryAccountNumber = AcNo;
        this->SalaryBalance = balance;
    }
    void PrintSalaryInfo() {
        cout << "Name: " << this->Name << endl;
        cout << "Occupation: " << this->Occupation << endl;
        cout << "Phone Number: " << this->PhoneNumber << endl;
        cout << "Account Number: " << this->SalaryAccountNumber << endl;
        cout << "Salary Balance: " << this->SalaryBalance << endl;
    }
    double TaxReturnSalary() {
        double tax = SalaryBalance*0.05;
        if(SalaryBalance >= 20000) {
            SalaryBalance-=tax;
            cout << Name << ", your tax amount is " << tax << endl;
        } else { cout << Name << ", your tax amount is " << 0 << endl; }
        return SalaryBalance;
    }
};

class ParentSavingAccount : public ParentSalaryAccount {
protected:
    string NameOfHolder;
    string JobTitle;
    string Telephone;
    char *SavingAccountNumber = "201.AB.11G";
    double SavingBalance = 60200;
public:
    ParentSavingAccount() {}
    ~ParentSavingAccount() {
        cout << NameOfHolder << ", Your current Saving balance is " << SavingBalance << endl;
    }
    void Get_Parent_Saving_Account_Info(string nm, string job, string phnNum, char AcNo[], double balance) {
        this->NameOfHolder = nm;
        this->JobTitle = job;
        this->Telephone = phnNum;
        this->SavingAccountNumber = AcNo;
        this->SavingBalance = balance;

        // Parent Salary Account
        char *str = &phnNum[0];
        ParentSalaryAccount::Name = nm;
        ParentSalaryAccount::Occupation = job;
        ParentSalaryAccount::PhoneNumber = str;

    }
    void PrintSavingInfo() {
        cout << "Name: " << this->NameOfHolder << endl;
        cout << "Occupation: " << this->JobTitle << endl;
        cout << "Phone Number: " << this->Telephone << endl;
        cout << "Account Number: " << this->SavingAccountNumber << endl;
        cout << "Salary Balance: " << this->SavingBalance << endl;
    }
    double TaxReturnSaving() {
        double tax = SavingBalance*0.03;
        if(SavingBalance >= 20000) {
            SavingBalance-=tax;
            cout << Name << ", your tax amount is " << tax << endl;
        } else { cout << Name << ", your tax amount is " << 0 << endl; }
        return SavingBalance;
    }
    void RecievedMoneyFromSalary() {
        double transfer = SalaryBalance*0.2;
        this->SavingBalance += transfer;
        SalaryBalance -= transfer;
        cout << "Transferring Balance " << transfer << " from Salary to Saving Account!" << endl;
    }
};

class ChildAccount : private ParentSavingAccount {
    double ChildBalance = 10200;
    string AccountName;
    string Title = "Student";
    string Mobile;
    string ChildAccountNumber;
public:
    ChildAccount() {}
    ~ChildAccount() {
        cout << AccountName << ", Your current child balance is " << ChildBalance << endl;
    }
    void Get_Child_Account_Info(string nm, string occ, string phnNum, string AcNo, double balance) {
        this->AccountName = nm;
        this->Title = occ;
        this->Mobile = phnNum;
        this->ChildAccountNumber = AcNo;
        this->ChildBalance = balance;

        // Parent Saving Account
        ParentSavingAccount::NameOfHolder = nm;
        ParentSavingAccount::JobTitle = occ;
        ParentSavingAccount::Telephone = phnNum;

        // Parent Salary Account
        char *str2 = &phnNum[0];
        ParentSalaryAccount::Name = nm;
        ParentSalaryAccount::Occupation = occ;
        ParentSalaryAccount::PhoneNumber = str2;
    }
    void PrintChildInfo() {
        cout << "Name: " << this->AccountName << endl;
        cout << "Occupation: " << this->Title << endl;
        cout << "Phone Number: " << this->Mobile << endl;
        cout << "Account Number: " << this->ChildAccountNumber << endl;
        cout << "Salary Balance: " << this->ChildBalance << endl;
    }
    double TaxReturnOfChild() {
        double tax = ChildBalance*0.016;
        if(ChildBalance >= 20000) {
            ChildBalance-=tax;
            cout << Name << ", your tax amount is " << tax << endl;
        } else { cout << Name << ", your tax amount is " << 0 << endl; }
        return ChildBalance;
    }
    void ReceivedAmountFromSaving() {
        double transfer = SavingBalance*0.2;
        this->ChildBalance += transfer;
        SavingBalance -= transfer;
        cout << "Transferring Balance " << transfer << " from Saving to Child Account!" << endl;
    }
};

int main() {
    ParentSalaryAccount sal;
    sal.Get_Parent_Salary_Account_Info("Shawon", "Student", "0123456789", "101.23a.4b", 40000);
    sal.PrintSalaryInfo();
    sal.TaxReturnSalary();

    cout << endl;

    ParentSavingAccount sav;
    sav.Get_Parent_Saving_Account_Info("Ibrahim", "Engineer", "11112222", "201.AB.11G", 60200);
    sav.PrintSavingInfo();
    sav.TaxReturnSaving();

    cout << endl;

    ChildAccount child;
    child.Get_Child_Account_Info("Jahid", "Doctor", "5555511111", "505.ART.62", 10200);
    child.PrintChildInfo();

    cout << endl;
}
