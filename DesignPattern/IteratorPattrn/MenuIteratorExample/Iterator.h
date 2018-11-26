#pragma once
#include "MenuItem.h"


class Iterator {
public:
	virtual bool hasNext() = 0;
	virtual MenuItem& next() = 0;
	virtual void remove() = 0;
};


class ArrayMenuIterator :public Iterator {
public:
	virtual bool hasNext() {
		if (m_currentPos < m_pArrayIter->count())
			return true;
		else return false;
	}
	virtual MenuItem& next() {
		return m_pArrayIter->get(m_currentPos++);
	}
	virtual void remove() {}
	ArrayMenuIterator(ArrayCollection *col):m_pArrayIter(col),m_currentPos(0){}
	~ArrayMenuIterator() { delete m_pArrayIter; }
private:
	ArrayCollection *m_pArrayIter;
	int m_currentPos;
};


class ListMenuIterator :public Iterator {
public:
	virtual bool hasNext() {

	}
	virtual MenuItem& next() {

	}
	virtual void remove() {}
	ListMenuIterator(ListCollection *col) :m_pListIter(col) {}
	~ListMenuIterator() { delete m_pListIter; }
private:
	ListCollection *m_pListIter;
};

