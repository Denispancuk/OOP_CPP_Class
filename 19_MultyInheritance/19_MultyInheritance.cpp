#include <iostream>
using namespace std;
class Engine {
    string fuelType;
    double volume;        
    int horsepower;     
public:
    Engine():fuelType("None"),volume(0),horsepower(0) {}
    Engine(string f,double v,int h) :fuelType(f), volume(v), horsepower(h) {}
    void ChangeFuelType(string fuelType) {
        this->fuelType = fuelType;
    }
};
class Wheel {
    int radius; 
    double pressure; 
    string season; 
public:
    Wheel():radius(0),pressure(0),season("None") {}
    Wheel(int r,double p,string s):radius(r),pressure(p),season(s) {}
    void ChangeSeason(string season) {
        this->season = season;
    }
    void ChangePressure(double pressure) {
        this->pressure = pressure;
    }
};
class Headlight {
    string type;
    int brightness;     
    bool isOn;   
public:
    Headlight():type("None"),brightness(0),isOn(false) {}
    Headlight(string t,int b,bool i):type(t),brightness(b),isOn(i) {}
    void ChangeIsOn() {
        isOn = !isOn;
    }
    void ChangeType(string type){
        this->type = type;
    }
    void ChangeBrightness(int brightness) {
        this->brightness = brightness;
    }
};

class Door {
    string side;   
    bool isOpen;         
    bool isLocked;     
public:
    Door():side("None"),isOpen(false),isLocked(false) {}
    Door(string s,bool IO,bool IL):side(s),isOpen(IO),isLocked(IL) {}
    void ChangeIsOpen() {
        isOpen = !isOpen;
    }
    void ChangeIsLocked() {
        isLocked = !isLocked;
    }
};
class Body {
private:
    string type;    
    string color;   
    string material; 
};
class Car {

};
int main()
{
    
}
