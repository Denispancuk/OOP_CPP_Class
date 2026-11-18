#include <iostream>
#include <windows.h>
using namespace std;

class Animal//abstact class 
{
protected:
    string name;
    string place;
    float weight;
public:
    Animal() :name("no name"), place("no place"), weight(0) {}
    Animal(string n, string p, float w) :name(n), place(p)
    {
        weight = (w > 0) ? w : 0;
    }
    void Show()const
    {
        cout << "Name : " << name << endl;
        cout << "Place : " << place << endl;
        cout << "Weight : " << weight << endl;
    }
    virtual void MakeSound() = 0;
};

class Fox :public Animal {
    int age;
    bool isCunning;
public:
    Fox():isCunning(true),age(0), Animal() {}
    Fox(bool isCunning,int age, string n, string p, float w):isCunning(isCunning),age(age), Animal(n, p, w) {}
    void ChangeIsCunning() {
        isCunning = !isCunning;
    }
    void AddAge() {
        age++;
    }
    void MakeSound() override{
        Beep(700, 60);  Sleep(20);
        Beep(900, 60);  Sleep(150);
        Beep(700, 60);  Sleep(20);
        Beep(900, 60);  Sleep(150);
        Beep(700, 60);  Sleep(20);
        Beep(900, 60);  Sleep(400);

        Beep(600, 80);  Sleep(5);
        Beep(800, 80);  Sleep(5);
        Beep(1000, 80); Sleep(5);
        Beep(1200, 80); Sleep(5);
        Beep(1400, 80); Sleep(5);
        Beep(1600, 150); Sleep(5);
        Beep(1700, 250); Sleep(5);

        Beep(1500, 80); Sleep(5);
        Beep(1300, 80); Sleep(5);
        Beep(1100, 80); Sleep(5);
        Beep(900, 80);  Sleep(5);
        Beep(700, 120); Sleep(5);
        Beep(500, 200); Sleep(500);

        Beep(800, 60);  Sleep(20);
        Beep(1000, 60); Sleep(300);

    }
};
class Rabbit :public Animal {
    float earLength;
    int age;
public:
    Rabbit():earLength(0),age(0), Animal() {}
    Rabbit(float earLenght,int age, string n, string p, float w):earLength(earLenght),age(age), Animal(n, p, w) {}
    void ChangeEarLength(float earLength){
        this->earLength = earLength;
    }
    void AddEarLength(float earLength){
        this->earLength += earLength;
    }
    void AddAge() {
        age++;
    }
    void MakeSound() override {
        Beep(1500, 30); Sleep(5);
        Beep(1650, 30); Sleep(5);
        Beep(1800, 30); Sleep(5);
        Beep(1950, 30); Sleep(80);

        Beep(1500, 30); Sleep(5);
        Beep(1650, 30); Sleep(5);
        Beep(1800, 30); Sleep(5);
        Beep(1950, 30); Sleep(80);

        Beep(1500, 30); Sleep(5);
        Beep(1650, 30); Sleep(5);
        Beep(1800, 30); Sleep(5);
        Beep(1950, 30); Sleep(5);
    }
};
class Plants {
protected:
    string name;
    string place;
    float height;
public:
    Plants() :name("no name"), place("no place"), height(0) {}
    Plants(string n, string p, float h) :name(n), place(p)
    {
        height = (h > 0) ? h : 0;
    }
    void Show()const
    {
        cout << "Name : " << name << endl;
        cout << "Place : " << place << endl;
        cout << "Height : " << height << endl;
    }
};
class Grass :public Plants {
    string color;
    bool isMedicinal;
public:
    Grass():color("None"),isMedicinal(false),Plants() {}
    Grass(string c,bool Medik, string n, string p, float h):color(c),isMedicinal(Medik),Plants(n,p,h) {}
    void ChangeColor(string color) {
        this->color = color;
    }
    void ChangeIsMedicinal(){
        isMedicinal = !isMedicinal;
    }
};
class Life {
    Fox* foxes;
    int countFox;

    Rabbit* rabbits;
    int countRabbit;

    Grass* grasses;
    int countGrass;
public:
    Life():foxes(nullptr), countFox(0),rabbits(nullptr), countRabbit(0),grasses(nullptr), countGrass(0) {}
    Life(int f,int r, int g){
        if (f > 0)
        {
            if (f > 5)
            {
                countFox = 5;
                foxes = new Fox[countFox];
            }
            else {
                countFox = f;
                foxes = new Fox[countFox];
            }
        }
        if (r > 0)
        {
            countRabbit = r;
            rabbits = new Rabbit[countRabbit];
        }
        if (g > 0)
        {
            countGrass = g;
            grasses = new Grass[countRabbit];
        }
        
    }
    void Cycle() {
        if (countGrass < countRabbit)
        {
            countGrass = 0;
            grasses = nullptr;
        }
        if (true)
        {

        }
    }
    ~Life() {
        if (foxes != nullptr)
        {
            delete[] foxes;
        }
        if (rabbits != nullptr)
        {
            delete[] rabbits;
        }
        if (rabbits != nullptr)
        {
            delete[] grasses;
        }
        
    }
};
void RollCall(Animal& a)
{
    a.MakeSound();
}
int main()
{




   


}