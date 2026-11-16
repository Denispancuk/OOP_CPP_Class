#include <iostream>
#include <windows.h>  
using namespace std;
void gotoxy(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
struct Point {
	int x;
	int y;
};
class Shape {
protected:
    string type;
public:
	Shape():type("None") {}
	Shape(string type):type(type) {}
	virtual void Print() const = 0;

};
class Line: public Shape {
	int start;
	int end;
public:
	Line():start(0),end(0){}
	Line(int point):start(point),end(point){}
	Line(int start,int end):start(start),end(end){}
	void Print() const override {

	}
};

class Rectangle :public Shape {
	int CoordTopLeftCorner;
	int width;
	int height;
public:
	Rectangle():CoordTopLeftCorner(0),width(0),height(0){}
	Rectangle(int dimension):CoordTopLeftCorner(0),width(dimension),height(dimension){}
	Rectangle(int width,int height):CoordTopLeftCorner(0),width(width),height(height){}
	Rectangle(int CoordTopLeftCorner,int width,int height):CoordTopLeftCorner(CoordTopLeftCorner),width(width),height(height){}
	void Print() const override {

	}
};
int main()
{
    
}
