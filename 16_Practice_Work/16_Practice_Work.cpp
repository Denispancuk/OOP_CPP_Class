#include <iostream>
using namespace std;
//Завдання N 1
//
//Створити базовий клас Employer(служ -
//
//    бовець) з чисто віртуальною функцією Print().Створіть
//
//    три похідних класи : President, Manager, Worker.Переви -
//
//    значите функцію Print() для виведення інформації, що
//
//    відповідає кожному типу службовця.
//
//    Завдання N 2
//
//    Створити базовий клас «Транспортний
//
//    засіб» і похідні класи «Автомобіль», «Велосипед», «Віз».
//
//    Підрахувати час і вартість перевезення пасажирів і
//
//    вантажів кожним транспортним засобом.
struct PIB {
    string FirstName;
    string MiddleName;
    string LastName;
    PIB():FirstName("No first Name"),MiddleName("No middle name"),LastName("No last name") {}
    PIB(string FN,string MN,string LN):FirstName(FN),MiddleName(MN),LastName(LN) {}
    void PrintPIB() const{
        cout << "First name: " << FirstName << endl;
        cout << "Middle name: " << MiddleName << endl;
        cout << "Last name: " << LastName << endl;
    }

};
class Employer {
protected:
    PIB Name;
    long long number;
    int salary;
public:
    Employer():Name(),number(0),salary(0){}
    Employer(string FN, string MN, string LN,long long number,int salary):Name({FN,MN,LN}), number(number), salary(salary) {}
    Employer(PIB name,long long number,int salary):Name(name), number(number), salary(salary) {}
    void ChangeNumber(long long number) {
        this->number = number;
    }
    void ChangeSalary(int salary) {
        this->salary = salary;
    }
    virtual void Print() const {
        Name.PrintPIB();
        cout << "Number: " << number << endl;
        cout << "Salary: " << salary << endl;
    }


};
class President : public Employer {
    string CompanyName;
    int CompanyMonthlyEarnings;
};
class Manager : public Employer {
    string NameCurrentProject;
    int CompletedProjects;
};
class Worker : public Employer {
    string WorkShop;
    int WorkHours;

};
int main()
{
    
}
