#include<iostream>
#define PI 3.14

class Circle {

public:
	Circle(float r):radious(r){}
	Circle(Circle &c):radious(c.radious){}

	float getArea() {
		return PI*radious*radious;
	}

	float getParameter() {
		return 2 * PI*radious;
	}

private:
	float radious;
};


class Square {

public:
	Square(float s):side(s){}
	Square(Square &rhs):side(rhs.side){}

	//Implicit conversion from circle to square

	
	Square(Circle &c) {
		side = (c.getParameter())/4;
	}
	
		float getArea() {
		return side*side;
	}
	float getParameter() {
		return 4 * side;
	}

private:
	float side;
};

int main() {

	Circle c1(7);
	Circle c2(14);

	Square s2(4);

	
	
	Square s2(c1);


	s2 = c2;


	getchar();
	return 0;
}