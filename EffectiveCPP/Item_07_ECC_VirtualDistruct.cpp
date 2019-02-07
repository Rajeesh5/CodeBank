#include<iostream>

class Base {

public:
	~Base() {
		std::cout << "Base distructed\n";
	}
};

class Derived:public Base {

public:
	~Derived() {
		std::cout << "Derived distructed\n";
	}
};

int main_07() {

	Base *bptr = new Derived();
	delete bptr;
	getchar();
	return 0;

}