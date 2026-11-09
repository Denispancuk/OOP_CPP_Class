#include <iostream>
using namespace std;

class Student {
    string name;
    int group;
    float AverageMark;
    float AverageAttendance;
public:
    Student():name("None"), group(-1),AverageMark(0),AverageAttendance(0){}
    Student(string n,int g, float AM, float AA):name(n), group(g),AverageMark(AM),AverageAttendance(AA){}
    void PrintInfo()const {
        cout << "Name: " << name << endl;
        cout << "Group: " << group << endl;
        cout << "Average Mark: " << AverageMark << endl;
        cout << "Average Attendance: " << AverageAttendance << endl;
    }
    void ChangeAverageMark(float AverageMark) {
        this->AverageMark = AverageMark;
    }
    void ChangeAverageAttendance(float AverageAttendance) {
        this->AverageAttendance = AverageAttendance;
    }
};
class Aspirant:Student
{
    string DisertationTopic;
    int DisertationCountPages;
    bool DisertationProgress;
public:
    Aspirant():DisertationTopic("None"), DisertationCountPages(0), DisertationProgress(false), Student() {}
    Aspirant(string DT,int d,bool DIS,string n,int g,float AM,float AA):DisertationTopic(DT), DisertationCountPages(0), DisertationProgress(DIS), Student(n, g, AM, AA) {}
    void Disertation(int CountPages) {
        DisertationCountPages += CountPages;
    }
    void SecureDisertation() {
        int Success = rand()%101;
        if (DisertationCountPages >= 500 and Success > 10)
        {
            DisertationProgress = true;
        }
    }


};
struct PIB {
    string FirstName;
    string MiddleName;
    string LastName;
public:
    PIB():FirstName("NoFirstName"),MiddleName("NoMiddleName"),LastName("NoLastName") {}
    PIB(string FN,string MN,string LN):FirstName(FN),MiddleName(MN),LastName(LN) {}
};
class Passport {
    PIB Name;
    string citizenship;
}
int main()
{
    srand(time(0));

}
