
#include<iostream>
#include"Iterator.h"
#include"MenuItem.h"

using namespace std;


class Collection {
	virtual Iterator* createIterator() = 0;
	virtual int count() = 0;
	virtual void append(MenuItem*) = 0;
};


class ArrayCollection:public Collection {

};

class ListCollection: public Collection {

};