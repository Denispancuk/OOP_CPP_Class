#include <iostream>
#include <windows.h>
using namespace std;
class Car {
protected:
    string model;
    int year;
    int speed;
    float volume;
public:
    Car():model("No model"), year(0),speed(0),volume(0)
    {

    }
    Car(string m,int y, float v):model(m),year(y),volume(v)
    {

    }
    void Drive() {
        cout << "I am a Car! I can drive with speed: " << speed << "km/h" << endl;
    }
    void setSpeed(int speed) {
        if (speed > 0)
        {
            this->speed = speed;
        }
        else {
            speed = 0;
        }
    }
    void Print()const {
        cout << "-------------Car--------------" << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Speed: " << speed << endl;
        cout << "Volume: " << volume << endl;
    }
};
class PoliceCar: public Car {
    int soundVolume;
public:
    PoliceCar():soundVolume(0), Car()
    {

    }
    PoliceCar(string n,int y,float v,int sound):soundVolume(sound), Car(n,y,v)
    {

    }
    void Drive()const {
        cout << "I am a Police car. I can drive with speed: " << speed << "km/h" << endl;
    }
    void Print()const {
        Car::Print();
        cout << "Sound volume: " << soundVolume << "db" << endl;
    }

};
int main()
{
    PoliceCar car("Renault Duster",2015,1.6,500);
    car.setSpeed(220);
    car.Print();
    car.Drive();

    
}
