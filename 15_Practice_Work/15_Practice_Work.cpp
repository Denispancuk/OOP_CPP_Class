#include <iostream>
using namespace std;
//Завдання 1:
//
//Створіть клас Shape який містить загальні параметри
//
//будь - якої фігури(ім, я, тип і тд).Визначте віртуальні методи :
//
//•Show – вивід на екран інформації про фігуру; •Show
//
//•GetArea – обчислення площі фігури; (•GetArea)
//
//Визначте похідні класи : прямокутник, коло, прямокутний трикутник, трикутник,
//
//трапеція зі своїми функціями площі.– кожний з яких буде
//
//містити притаманні даній фігурі характеристики та перевизначати(override)
//
//алгоритми методів базового класу Shape.
//
//Також створити функцію TestShape, яка приймає фігуру та відображає її
//
//інформацію включаючи площу.
//
//В main протестувати роботу, передавши в функцію різні фігури.
class Shape {
protected:
    string name;
public:
	Shape():name("No name") {}
	Shape(string name):name(name) {}
	virtual void Show() const {
		cout << "Name: " << name << endl;
	}
	virtual void GetArea() const {
		return;
	}
};

class Rectangle : public Shape {
	int width;
	int lenght;
public:
	Rectangle():width(0), lenght(0), Shape("Rectangle") {}
	Rectangle(int width, int lenght):width(width), lenght(lenght),Shape("Rectangle") {}
	void GetArea() const override{
		cout << "Area: " << width * lenght << endl;
	}
	void Show() const override{
		cout << "Name: " << name << endl;
		cout << "Width: " << width << endl;
		cout << "lenght: " << lenght << endl;
		GetArea();

	}
};
class Triangle : public Shape {
	int FirstSide;
	int SecondSide;
	int height;
public:
	Triangle():FirstSide(0), SecondSide(0),height(0), Shape("Triangle") {}
	Triangle(int FirstSide, int SecondSide,int height):FirstSide(FirstSide), SecondSide(SecondSide),height(height), Shape("Triangle") {}
	void GetArea() const override{
		cout << "Area: " << 0.5 * FirstSide * height << endl;
	}
	void Show() const override{
		cout << "Name: " << name << endl;
		cout << "FirstSide: " << FirstSide << endl;
		cout << "SecondSide: " << SecondSide << endl;
		cout << "Height: " << height << endl;
		GetArea();
	}
};
class RightTriangle : public Shape {
	int FirstSide;
	int SecondSide;
public:
	RightTriangle() :FirstSide(0), SecondSide(0), Shape("Triangle") {}
	RightTriangle(int FirstSide, int SecondSide) :FirstSide(FirstSide), SecondSide(SecondSide), Shape("Triangle") {}
	void GetArea() const override {
		cout << "Area: " << 0.5 * FirstSide * SecondSide << endl;
	}
	void Show() const override {
		cout << "Name: " << name << endl;
		cout << "FirstSide: " << FirstSide << endl;
		cout << "SecondSide: " << SecondSide << endl;
		GetArea();
	}
};
class Circle : public Shape {
	int Radius;
	int Diameter;

};
int main()
{
    std::cout << "Hello World!\n";
}

