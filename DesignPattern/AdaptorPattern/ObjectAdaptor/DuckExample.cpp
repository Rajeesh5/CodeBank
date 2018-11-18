#include<iostream>

using namespace std;


class Duck {
public:
	virtual void quack()=0;
	virtual void fly() = 0;
};

class MullarDuck :public Duck{

public:
	virtual void quack() {
		cout << "Sound::Quack\n";
	}
	virtual void fly() {
		cout << "I am flying..\n";
	}
};


//Turkey Interface, Diffrent then Duck

class Turkey {
public:
	virtual void gobble() = 0;
	virtual void fly() = 0;
};


class WildTurkey:public Turkey {
public:
	virtual void gobble() {
		cout << "Sound::gobble..gobble\n";
	}
	virtual void fly() {
		cout << "I am short flyer..\n";
	}

};


class TurkeyAdaptor :public Duck {
	Turkey *turkey;						//Adaptee Object, example of object adaptor.
public:
	TurkeyAdaptor(Turkey *turkey) {
		this->turkey = turkey;
	}
	void quack() {
		turkey->gobble();
	}

	void fly() {
		for (int i = 0; i < 5; i++) {
			turkey->fly();
		}
	}
};



void duckTest(Duck *duck) {
	duck->fly();
	duck->quack();
}


int main() {

	Duck *duck1 = new MullarDuck();

	duckTest(duck1);

	Turkey *turkey = new WildTurkey();

	// Wrap a turkey in a TurkeyAdapter so that it behaves like duck 

	TurkeyAdaptor adpt(turkey);

	duckTest(&adpt);

	getchar();
		 
}




