#include<iostream>

using namespace std;


template<typename T>
class SmartPtr {
public:
	virtual ~SmartPtr() {
		//if(*this owns pointee or pData), for ref cnt based smart pointer.
		delete pData;
	}


	SmartPtr(T *realPtr = 0) :pData(realPtr) {}
	SmartPtr(SmartPtr<T> &rhs);
	SmartPtr<T>& operator=(SmartPtr<T> &rhs);
	T& operator *()const;
	T* operator ->()const;

	bool isNull();		//to test the nullability
	//operator T*();	//No samrt to dumb pointer convertion operator methods

	template<typename newType>
	operator SmartPtr<newType>() {
		return SmartPtr<newType>(pData);
	}



private:
	T * pData;
};


template<typename T>
SmartPtr<T>::SmartPtr(SmartPtr<T> &rhs) {
	pData = rhs.pData;			//Transfer ownership form rhs to pData. 
	rhs.pData = 0;				//rhs no longer have ownership.
}

template<typename T>
SmartPtr<T>& SmartPtr<T>::operator =(SmartPtr<T> &rhs) {
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


class MusicProduct {
public:
	MusicProduct(const string& title);
	virtual void play() const = 0;
	virtual void displayTitle() const = 0;
	
};
class Cassette : public MusicProduct {
public:
	Cassette(const string& title);
	virtual void play() const;
	virtual void displayTitle() const;
	
};
class CD : public MusicProduct {
public:
	CD(const string& title);
	virtual void play() const;
	virtual void displayTitle() const;
	
};

class CasSingle :public Cassette {
public:
	CasSingle(const string& title);
	virtual void play() const;
	virtual void displayTitle() const;
};


//void displayAndPlay( MusicProduct* pmp, int numTimes)
//{
//	for (int i = 1; i <= numTimes; ++i) {
//		pmp->displayTitle();
//		pmp->play();
//	}
//}


void displayAndPlay( const SmartPtr<MusicProduct> &pmp, int numTimes)
{
	for (int i = 1; i <= numTimes; ++i) {
		pmp->displayTitle();
		pmp->play();
	}
}


int main() {

	SmartPtr<Cassette> funMusic(new Cassette("Alapalooza"));
	SmartPtr<CD> nightmareMusic(new CD("Disco Hits of the 70s"));
	SmartPtr<CasSingle> cas(new CasSingle("Best one"));
	displayAndPlay(funMusic, 10); 									// error!
	displayAndPlay(nightmareMusic, 0); 								// error!
	displayAndPlay(cas, 3);

	getchar();
	return 0;
}