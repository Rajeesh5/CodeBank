
#pragma once

#include"Iterator.h"
#include"MenuItem.h"
#include <list>



#define MAX_SIZE 10
using namespace std;


class Collection {
public:
	virtual Iterator* createIterator()=0;
	virtual int count() = 0;
	virtual void append(MenuItem& ) = 0;
	virtual MenuItem& get(int) = 0;
};


class ArrayCollection :public Collection {
public:
	ArrayCollection() {
		m_itemCount = 0;
	}
	Iterator* createIterator() {
		return (new ArrayMenuIterator(this));
	}
	void append(MenuItem& item) {
		if (count() < MAX_SIZE)
			m_array[m_itemCount++] = item;
	}
	int count() {
		return m_itemCount;
	}
	MenuItem& get(int index) {
		return m_array[index];
	}
	~ArrayCollection(){}
private:
	MenuItem m_array[MAX_SIZE];
	int m_itemCount;
};

class ListCollection : public Collection {
public:
	Iterator* createIterator() {
		return (new ListMenuIterator(this));
	}
	void append(MenuItem& item) {
		m_menuList.push_back(item);
	}

	int count() {
		return m_menuList.size();
	}
	MenuItem& get(int index) {
		return MenuItem();
	}

private:
	list <MenuItem> m_menuList;
};

