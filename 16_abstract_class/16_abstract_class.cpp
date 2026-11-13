#include <iostream>
using namespace std;

class Animal {
protected:
    string name;
    string place;
    float weight;
public:
    Animal():name("No name"), place("No place"),weight(0){}
    Animal(string n,string p,float w):name(n),place(p)
    {
        weight = (w > 0) ? w : 0;
    }
    void Show()const {
        cout << "name: " << name << endl;
        cout << "place: " << place << endl;
        cout << "weight: " << weight << endl;

    }
    virtual void MakeSound() {};
    void Move() {
        cout << "I am moving......." << endl;
    }
};
class Dog : public Animal {
    string bree;
public:
    Dog():bree("No Bree"), Animal(){}
    Dog(string name, string place, float weight,string b):bree(b), Animal(name,place,weight){}
    void MakeSound(){
        cout << "Gav-gav-gav" << endl;
    }
    void Move() {
        cout << "I am running and jumping......" << endl;
    }
    void Show() {
        Animal::Show();
        cout << "Bree dog: " << bree << endl;
    }
};
class Parrot :public Animal {
    float flyHeight;
    bool CanSpeak;
public:
    Parrot():flyHeight(0),CanSpeak(false),Animal(){}
    Parrot(string name,string place,float weight, float FH,bool speak):flyHeight(FH),CanSpeak(speak),Animal(name,place,weight){}
    void MakeSound() {
        cout << "Kar-Kar-Kar" << endl;
    }
    void Move() {
        cout << "I am flying up to " << flyHeight << "and i can speak or not: " << CanSpeak << endl;
    }
    void Show() {
        Animal::Show();
        cout << "Fly Height: " << flyHeight << endl;
        cout << "Can Speak: " << CanSpeak << endl;
    }
};
class Reptile : public Animal {
    float swimDeep;
public:
    Reptile() :swimDeep(), Animal(){}
    
};
int main()
{
    /*Dog dog("Roki", "Flat", 12, "Taksa");
    dog.Show();
    dog.MakeSound();
    dog.Move();*/
    Parrot parrot("Kesha", "House", 0.6, 5, true);

}
