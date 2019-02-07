#include<iostream>

class Test {

	Test(const Test &rhs);		//If you are calling, then need to provide body.
								//Here want to prevent to call, dont provide defination. 
	Test& operator=(const Test &rhs);

public:
	Test(){}
	
};


class Uncopyable {
protected:					// allow construction
	Uncopyable() {}			// and destruction of
	~Uncopyable() {}		// derived objects...
private:
	Uncopyable(const Uncopyable&);			// ...but prevent copying
	Uncopyable& operator=(const Uncopyable&);
};

class TestUncopyable :public Uncopyable {

};



int main_06() {

	/*
	Test t1, t2;
	t1 = t2;			//Complile time error, function inaccessable.

	Test t3(t1);		//Compile time error. function inaccessable.


	TestUncopyable p1, p2;

	p1 = p2;			//Canot be refrenced its deleted function.
	*/
	getchar();
	return 0;
}