#include <iostream>
using namespace std;
class Student {
    string name;
    int age;
    int* marks;
    int countMark;
public:
    Student():name("No name"),age(0),marks(nullptr),countMark(0)
    {

    }
    Student(string name):name(name),age(age)
    {
        countMark = rand() % 15 + 1;
        marks = new int[countMark];
        for (int i = 0; i < countMark; i++)
        {
            marks[i] = rand() % 12 + 1;
        }
    }
    void Print()const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Marks: ";
        for (int i = 0; i < countMark; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl << endl;
    }
    ~Student() {
        if (marks != nullptr)
        {
            delete[]marks;
        }
    }
};
int main()
{
    
}
