#include<iostream>
#include<string.h>
using namespace std;

class Person {
	int age;
	char* pName;


	char* initName(char *nm) {
		
		int size = strlen(nm);
		char *tmp = new char[size + 1];
		memcpy(tmp, nm, strlen(nm));
		tmp[size] = '\0';
		return tmp;
	}


public:
	Person() : pName(0), age(0) {}
	Person(char* nm, int age) : pName(initName(nm)), age(age){	}
	/*
	Person(char* nm, int age) {
		int size = strlen(nm);
		pName = new char[size+ 1];
		memcpy(pName, nm,strlen(nm));
		pName[size] = '\0';
		this->age = age;
	}
	*/
	~Person() {
		delete pName;
		age = 0;
	}

	void Display()const
	{
		printf("Name = %s Age = %d \n", pName, age);
	}
	void Shout()const
	{
		printf("Ooooooooooooooooo\n");
	}

	void midifiedPreson() {
		age = 100;
	}
};

template<typename T>
class SmartPtr {
public:
	virtual ~SmartPtr() {

		//if(*this owns pointee or pData)
		delete pData;
	}


	SmartPtr(T *realPtr = 0) :pData(realPtr) {}
	SmartPtr(const SmartPtr<T> &rhs);
	SmartPtr<T>& operator=(const SmartPtr<T> &rhs);
	T& operator *()const;
	T* operator ->()const;

	operator void * () {			//Conversion method Class to void ptr.
		if (pData == NULL) {
			return 0;
		}
		else return (void*)1;
	}

	operator T*() { return pData; }

private:
	T * pData;
};

void showPerson( Person *p) {			//method 1.

	//p->Shout();
	//We can also modify the p, now this is a big problem.
	p->midifiedPreson();

	p->Display();
}

/*
void showPerson(SmartPtr<Person> &p) {		//method 2.
	Person *ptr = p;

	ptr->Display();
	ptr->Shout();

	//Both method 1 & 2 are same.
}
*/
template<typename T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> &rhs) {
	pData = rhs.pData;			//Transfer ownership form rhs to pData. 
	rhs.pData = 0;				//rhs no longer have ownership.
}

template<typename T>
SmartPtr<T>& SmartPtr<T>::operator =(const SmartPtr<T> &rhs) {
	if (this == &rhs)
		return *this;

	delete pData;
	pData = rhs.pData;
	rhs.pData = 0;
	return *this;


}

template<typename T>
T& SmartPtr<T>::operator*()const {
	//Perform smart pointer processing.
	//For ex-Leazy fatching, because now we need actual pointer.
	//...
	return *pData;
}

template<typename T>
T* SmartPtr<T>::operator->()const {
	//similarly, Perform smart pointer processing.
	return pData;

}




template<class T>					// template for smart ptrs to objects in a distributed DB
class DBPtr { 
public: 
	DBPtr(T *realPtr = 0);			// create a smart ptr to a DB object given a local dumb pointer to it
	DBPtr(DataBaseID id);			// create a smart ptr to a DB object given its unique DB identifier
	//...							// other smart ptr functions as above

	T& operator *()const;
	T* operator ->()const;
private:
	T * pontee;
}; 


class Tuple {						// class for database tupple
public:
	//...
	void displayEditDialog();		// present a graphical dialog box allowing a user to edit the tuple
	bool isValid() const;			// return whether *this passes validity check
								
};

// class template for making log entries whenever a T object is modified;

template<class T>
class LogEntry {
public:
	LogEntry(const T& objectToBeModified);
	~LogEntry();
};

void editTuple(DBPtr<Tuple>& pt)
{
	LogEntry<Tuple> entry(*pt); // make log entry for this editing operation; 
								// repeatedly display edit dialog until valid values are provided
	do {
		pt->displayEditDialog();
	} while (pt->isValid() == false);
}



int main() {





	SmartPtr<Person> sp(new Person("Rajeev Sharma", 32));

	showPerson(sp);
	




	//NULL check.


	void * vp = sp;

	void* tem  = sp;

/*	
	if (sp) {
		sp->Display();
	}
	if (sp == 0) {
		sp->Display();
	}

	if (sp != NULL) {
		sp->Display();
	}

	if (!sp) {
		sp->Display();
	}
	*/
	getchar();

	return 0;
}