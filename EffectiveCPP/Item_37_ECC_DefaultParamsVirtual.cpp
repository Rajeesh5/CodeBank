#include<iostream>

using namespace std;

class Shape {							// a class for geometric shapes
public:
	enum ShapeColor { Red, Green, Blue };
	// all shapes must offer a function to draw themselves
	virtual void draw(ShapeColor color = Red) const = 0;

};
class Rectangle : public Shape {
public:
	// notice the different default parameter value — bad!
	virtual void draw(ShapeColor color = Green) const {

	}
	
};
class Circle : public Shape {
public:
	virtual void draw(ShapeColor color = Blue) const {

	}
	
};

int main() {

	Shape *ps; // static type = Shape*
	Shape *pc = new Circle; // static type = Shape*
	Shape *pr = new Rectangle; // static type = Shape*

	pc->draw(Shape::ShapeColor::Red); // calls Circle::draw(Shape::Red)
	pr->draw(Shape::Red); // calls Rectangle::draw(Shape::Red)

	getchar();
	return 0;
}