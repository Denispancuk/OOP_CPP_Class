#include <iostream>
using namespace std;

struct PIB {
    string FirstName;
    string MiddleName;
    string LastName;
public:
    PIB() :FirstName("NoFirstName"), MiddleName("NoMiddleName"), LastName("NoLastName") {}
    PIB(string FN, string MN, string LN) :FirstName(FN), MiddleName(MN), LastName(LN) {}

    void ShowName() {
        cout << "First name: " << FirstName << endl;
        cout << "Middle name: " << MiddleName << endl;
        cout << "Last name: " << LastName << endl;
    }

};

class Student {
protected:
    PIB name;
    int group;
    float AverageMark;
    float AverageAttendance;
public:
    Student() :name(), group(-1), AverageMark(0), AverageAttendance(0) {}
    Student(string FN, string MN, string LN, int g, float AM, float AA) :name(FN, MN, LN), group(g), AverageMark(AM), AverageAttendance(AA) {}
    Student(PIB name, int g, float AM, float AA) :name(name), group(g), AverageMark(AM), AverageAttendance(AA) {}

    void PrintInfo() {
        name.ShowName();
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




class Aspirant :public Student
{
    string DisertationTopic;
    int DisertationCountPages;
    bool DisertationProgress;
public:
    Aspirant() :DisertationTopic("None"), DisertationCountPages(0), DisertationProgress(false), Student() {}
    Aspirant(string DT, int DCP, bool DIS, PIB n, int g, float AM, float AA) :DisertationTopic(DT), DisertationCountPages(DCP), DisertationProgress(DIS), Student(n, g, AM, AA) {}
    void Disertation(int CountPages) {
        DisertationCountPages += CountPages;
    }
    void SecureDisertation() {
        int Success = rand() % 101;
        if (DisertationCountPages >= 500 and Success > 10)
        {
            DisertationProgress = true;
        }
    }


};

class Passport {
protected:
    PIB Name;
    string Citizenship;
    char Gender;
    string PlaceOfBitrh;
    short IssuingAuthority;
public:
    Passport():Name(),Citizenship("None"),Gender('N'),PlaceOfBitrh("None"),IssuingAuthority(0) {}
    Passport(string FN, string MN, string LN, string citizenship, char gender, string PlaceOFBirth, short IssuingAuthority) :Name(FN, MN, LN), Citizenship(citizenship), Gender(gender), PlaceOfBitrh(PlaceOFBirth), IssuingAuthority(IssuingAuthority) {}
    Passport(PIB name,string citizenship,char gender,string PlaceOFBirth,short IssuingAuthority):Name(name),Citizenship(citizenship),Gender(gender),PlaceOfBitrh(PlaceOFBirth),IssuingAuthority(IssuingAuthority) {}
    void PrintPassport() {
        Name.ShowName();
        cout << "Citizenship: " << Citizenship << endl;
        cout << "Gender: " << Gender << endl;
        cout << "PlaceOfBitrh: " << PlaceOfBitrh << endl;
        cout << "IssuingAuthority: " << IssuingAuthority << endl;

    }
    void ChangeCitizenship(string Citizenship) {
        this->Citizenship = Citizenship;
    }
};
class ForeignPassport : public Passport {

};
int main()
{

    srand(time(0));

}