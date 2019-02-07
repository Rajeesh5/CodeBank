#include<iostream>


class Airport {};

class Airplane {
public:
	virtual void fly(const Airport& destination) = 0;
};


void Airplane::fly(const Airport& destination) { 		// an implementation of a pure virtual function
	std::cout << "default code for flying an airplane to the given destination\n";
}

class ModelA : public Airplane {
public:
	virtual void fly(const Airport& destination) {
		Airplane::fly(destination);
	}
};

class ModelB : public Airplane {
public:
	virtual void fly(const Airport& destination) {
		Airplane::fly(destination);
	}
};

class ModelC : public Airplane {
public:
	/*
	virtual void fly(const Airport& destination) {
		std::cout << "code for flying a ModelC airplane to the given destination\n";
	}
	*/
};


int main() {


	Airplane *ap = new ModelC();

	getchar();

	return 0;
	
}