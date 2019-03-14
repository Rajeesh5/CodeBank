#include<iostream>

class Animal {
public:
	virtual Animal& operator=(const Animal& rhs){
		return *this;
	}
	
};
class Lizard : public Animal {
public:
	virtual Lizard& operator=(const Animal& rhs){
		return *this;
	}

};
class Chicken : public Animal {
public:
	virtual Chicken& operator=(const Animal& rhs){
		return *this;
	}

};

int main() {
	Lizard liz;
	Chicken chick;
	Animal *pAnimal1 = &liz;
	Animal *pAnimal2 = &chick;

		*pAnimal1 = *pAnimal2; // assign a chicken to
							   // a lizard!

	getchar();
	return 0;
}