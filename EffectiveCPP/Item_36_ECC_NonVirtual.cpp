#include<iostream>

class Dog {
public:
	void bark() {
		std::cout << "Dog bark\n";
	}
};

class SpacialDog :public Dog {
public:
	
	void bark() {
		std::cout << "spaical Dog bark\n";
	}
	
};

int main() {

	


	
	SpacialDog sd;

	Dog *dp = &sd;
	dp->bark();

	SpacialDog *sdp = &sd;
	sdp->bark();

	


	getchar();
	return 0;

}