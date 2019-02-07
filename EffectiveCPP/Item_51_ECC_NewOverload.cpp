#include<iostream>


//Global operator new overload.
void * operator new(std::size_t size) throw(std::bad_alloc) {

	while (true) {

		void *pMem = malloc(size);			//Allocate the memory
		if (pMem)
			return pMem;					//return if success.

		std::new_handler currentHandler = std::set_new_handler(0);	//Get new handler
		std::set_new_handler(currentHandler);

		if (currentHandler)
			(*currentHandler)();			//Invoke new handler	
		else 
			throw std::bad_alloc();			//If new handler is null, throw execption.

	}
}

//Class scope operator new overload

class Dog {
public:
	static void* operator new(std::size_t size) throw (std::bad_alloc) {

		if (size == sizeof(Dog))		//This is why? because of YellowDog having diffrent size
			costomNewForDog();	
		else
			::operator new(size);		//For that we called globle operator new. this is one solution 
										//Other one is, we can define oprator new for YellowDog as well as.	
	}

	static void operator delete(void *vptr) {
		costomDeleteForDod();
		free(vptr);
	}

	virtual ~Dog() {}					//Solution, when base class pointer hold derived class object.
};

class YellowDog:public Dog {
	int age;

public:

	static void operator delete(void *vptr) {
		costomDeleteForDod();
		free(vptr);
	}

};


int main() {

	YellowDog *yd = new YellowDog();

	delete yd;

	Dog *dptr = new YellowDog();
	delete dptr;			//Do you see any problem with this stmt, It will only
							//delete the Dog object because operator delete is not virtual.
							//And we canot declare function which is static and virual as well as.

							//soluion is defining virtual distructor for Dog.

}
