#include<iostream>

using namespace std;

//Pizza:PeppyPaneer, Farmhouse, Margherita, ChickenFiesta 
//Pizza Costs are-

#define PEPPYPANEERCOST   1.10
#define FARMHOUSECOST     2.20
#define MARGHERITACOST    1.75
#define CHICKENFIESTACOST 3.75

//Topping:FreshTomato, Paneer, Jalapeno, Capsicum, Barbeque
//Topping Costs are-

#define FRESHTOMATOCOST 0.20
#define PANNERCOST      0.30
#define JALAPENACOST    0.50
#define CAPSICUMCOST    0.10
#define BARBEQUECOST    0.25


class Pizza {
public:	
	virtual string getDiscription() = 0;
	virtual double getCost() = 0;
};

class PeppyPaneer :public Pizza {
	string discription;
	double cost;
public:
	PeppyPaneer() {
		discription = "PeppyPaneerPizza";
		cost = PEPPYPANEERCOST;
	}
	string getDiscription() {
		return discription;
	}
	double getCost() {
		return cost;
	}
};

class Farmhouse : public Pizza {
	string discription;
	double cost;
public:
	Farmhouse() {
		discription = "FarmhousePizza";
		cost = FARMHOUSECOST;
	}
	string getDiscription() {
		return discription;
	}
	double getCost() {
		return cost;
	}
};

class Margherita :public Pizza {

	string discription;
	double cost;
public:
	Margherita() {
		discription = "MargheritaPizza";
		cost = MARGHERITACOST;
	}
	string getDiscription() {
		return discription;
	}
	double getCost() {
		return cost;
	}
};

class ChickenFiesta :public Pizza {
	string discription;
	double cost;
public:
	ChickenFiesta() {
		discription = "ChickenFiestaPizza";
		cost = CHICKENFIESTACOST;
	}
	string getDiscription() {
		return discription;
	}
	double getCost() {
		return cost;
	}
};


class Topping:public Pizza {
public:
	Pizza *pizza;
};

class FreshTomatoTopping :public Topping {
	//Pizza *pizza;

public:
	FreshTomatoTopping(Pizza *pizza) {
		this->pizza = pizza;
	}

	string getDiscription() {
		return pizza->getDiscription() + " With FreshTomatoTopping";
	}

	double getCost() {
		return pizza->getCost() + FRESHTOMATOCOST;
	}

};

class PaneerTopping :public Topping {
	//Pizza *pizza;

public:
	PaneerTopping(Pizza *pizza) {
		this->pizza = pizza;
	}

	string getDiscription() {
		return pizza->getDiscription() + " With PaneerTopping";
	}

	double getCost() {
		return pizza->getCost() + PANNERCOST;
	}

};

class JalapenoTopping :public Topping {
	//Pizza *pizza;

public:
	JalapenoTopping(Pizza *pizza) {
		this->pizza = pizza;
	}
	string getDiscription() {
		return pizza->getDiscription() + " With JalapenoTopping";
	}

	double getCost() {
		return pizza->getCost() + JALAPENACOST;
	}
};

class CapsicumTopping :public Topping {
	//Pizza *pizza;
public:
	CapsicumTopping(Pizza *pizza) {
		this->pizza = pizza;
	}
	string getDiscription() {
		return pizza->getDiscription() + " With CapsicumTopping";
	}

	double getCost() {
		return pizza->getCost() + CAPSICUMCOST;
	}

};

class BarbequeTopping :public Topping {
	//Pizza *pizza;
public:
	BarbequeTopping(Pizza *pizza) {
		this->pizza = pizza;
	}
	string getDiscription() {
		return pizza->getDiscription() + " With BarbequeTopping";
	}

	double getCost() {
		return pizza->getCost() + BARBEQUECOST;
	}
};


int main() {


	//There are two ways to call in main. choose any of one...

	/*
	PeppyPaneer p1;
	FreshTomatoTopping t1(&p1);
	FreshTomatoTopping t2(&t1);
	CapsicumTopping t3(&t2);	
	std::cout << t3.getDiscription().c_str() << "::"<< t3.getCost()<<endl;
	*/


	/*
	Pizza *p1 = new ChickenFiesta();
	p1 = new BarbequeTopping(p1);
	p1 = new FreshTomatoTopping(p1);
	std::cout << p1->getDiscription().c_str() << "::" << p1->getCost() << endl;
	*/

	getchar();
}
