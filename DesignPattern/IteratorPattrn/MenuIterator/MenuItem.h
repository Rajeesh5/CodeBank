#pragma once
#include<string>

class MenuItem
{
public:
	MenuItem() {}
	MenuItem(std::string nm, std::string disc, float prc, bool var) :
		name(nm), discription(disc), price(prc), isVeg(var) {}
	~MenuItem() {}
	std::string getName() { return name; }
	std::string getDiscription() { return discription; }
	float getPrice() { return price; }
	bool isVegeterian() { return isVeg; }
private:
	std::string name;
	std::string discription;
	float price;
	bool isVeg;

};
