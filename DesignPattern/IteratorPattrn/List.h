#pragma once
#include"Iterator.h"

template <class Item>

class List {

public:
	virtual Iterator<Item> * CreateIterator() const = 0;
	virtual unsigned int Count() const = 0;
	virtual void Append(Item item) = 0;
};