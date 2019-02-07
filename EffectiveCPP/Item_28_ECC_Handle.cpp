#include<iostream>
#include<memory>




class Point { 							// class for representing points
public:
	Point(int a, int b) :x(a), y(b) {}
	void setX(int newVal) { x = newVal; }
	void setY(int newVal) { y = newVal; }
private:
	int x, y;
};

/*
//Design 1, flow in this design.
struct RectData { 							// Point data for a Rectangle
	RectData(const Point &p1, const Point &p2) :ulhc(p1), lrhc(p2) {}
	Point ulhc; 							// ulhc = “ upper left-hand corner”
	Point lrhc; 							// lrhc = “ lower right-hand corner”
};

class Rectangle {
	
public:

	Rectangle(const Point &p1, const Point &p2) : pData(new RectData(p1,p2 )) { }

	Point& upperLeft() const { return pData->ulhc; }
	Point& lowerRight() const { return pData->lrhc; }
	
private:
	std::tr1::shared_ptr<RectData> pData;
	
};
*/



class Rectangle {

public:

	Rectangle(const Point &p1, const Point &p2) :ulhc(new Point(p1)), lrhc(new Point(p2)) {}
	
	Point& upperLeft() const { return *ulhc; }
	Point& lowerRight() const { return *lrhc; }

	Rectangle() {
		delete ulhc;
		delete lrhc;
	}
private:
	
	Point *ulhc;
	Point *lrhc;
};


int main() {

	Point coord1(0, 0);
	Point coord2(100, 100);
	const Rectangle rec(coord1, coord2);

	rec.upperLeft().setX(50);

	getchar();
	return 0;
}