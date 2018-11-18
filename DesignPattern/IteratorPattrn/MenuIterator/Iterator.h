#pragma once
#include "MenuItem.h"

class Iterator {
public:
	virtual void First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual MenuItem CurrentItem() const = 0;

};

class ArrayMenuIterator:public Iterator {

};

class ListMenuIterator :public Iterator {

};