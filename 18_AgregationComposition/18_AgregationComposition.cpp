#include <iostream>
using namespace std;
enum Type{None,Standart,XL,XXL};
class Cartridge {
    float volume;
    string color;
    Type type;
public:
    Cartridge():volume(0),color("no color"),type(None) {}
    Cartridge(float v,string c,Type t):volume(v),color(c),type(t) {}
    void ShowInfo()const {
        cout << "Volume: " << volume << endl;
        cout << "Color: " << color << endl;
        cout << "Type: ";
        switch (type)
        {
        case None:
            cout << "None" << endl;
            break;
        case Standart:
            cout << "Standart" << endl;
            break;
        case XL:
            cout << "XL" << endl;
            break;
        case XXL:
            cout << "XXL" << endl;
            break;
        }
    }
};

class Scaner {
    float scanResolution;
    float height, width;
public:
    Scaner():scanResolution(0),height(0),width(0){}
    Scaner(float s, float h, float w):scanResolution(s),height(h),width(w){}
    void ShowInfo()const {
        cout << "Scan resolution: " << scanResolution << endl;
        cout << "Area scanning: " << height << "x" << width << endl;
    }
};
class Document {
    string name;
    string format;
    int pages;
public:
    Document() :name("None"), format("None"), pages(0) {}
    Document(string n, string f, int a) :name(n), format(f), pages(a) {}

};
class Printer {
    string model;
    Cartridge* cartriges;
    int countCartridges;
    Scaner scanner;
    Document* doc;
public:
    Printer():model("None"),cartriges(nullptr),countCartridges(0),scanner() {}
    Printer(string m, float s, float h, float w):model(m){
        countCartridges = 4;
        cartriges = new Cartridge[countCartridges];
        cartriges[0] = Cartridge(300, "Red", Type::Standart);
        cartriges[1] = Cartridge(300, "Green", Type::Standart);
        cartriges[2] = Cartridge(300, "Blue", Type::Standart);
        cartriges[3] = Cartridge(300, "Black", Type::Standart);
    }
    void Scan() {
        cout << "Scanning............." << endl;
    }
    void PrintDocument() {
        cout << "Print document........." << endl;
    }
    void PrintSettings() {
        for (int i = 0; i < countCartridges; i++)
        {
            cartriges[i].ShowInfo();
        }scanner.ShowInfo();
    }
    void AddDoc(Document* doc) {
        this->doc = doc;
    }
};

int main()
{
    
}
