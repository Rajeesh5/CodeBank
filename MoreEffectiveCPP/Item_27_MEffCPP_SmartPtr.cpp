#include<iostream>
using namespace std;

class Person {
	int age;
	char* pName;


	//char* initName(char *nm) {
	//	char *tmp = new char[strlen(nm + 1)];
	//	strcpy(tmp, nm);
	//	return tmp;
	//}


public:
	Person() : pName(0), age(0)	{}
	//Person(char* nm, int age) : pName(initName(nm)), age(age){	}
	Person(char* nm, int age) {
		pName= new char[strlen(nm + 1)];
		strcpy(pName, nm);
		this->age = age;
	}
	~Person(){
		delete pName;
		age = 0;
	}

	

	void Display()
	{
		printf("Name = %s Age = %d \n", pName, age);
	}
	void Shout()
	{
		printf("Ooooooooooooooooo\n");
	}
};

template<typename T>
class SmartPtr {
public:
	virtual ~SmartPtr() {

		//if(*this owns pointee or pData)
		delete pData;
	}


	SmartPtr(T *realPtr=0):pData(realPtr){}
	SmartPtr(const SmartPtr<T> &rhs);
	SmartPtr<T>& operator=(const SmartPtr<T> &rhs);
	T& operator *()const;
	T* operator ->()const;

	operator void *() {
		if (pData == NULL) {
			return 0;
		}
		else return 1;
	}

private:
	T * pData;
};

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

int main() {

	SmartPtr<Person> sp( new Person("Rajeev Sharma", 32));



	//NULL check.
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
	

	getchar();
	return 0;
}