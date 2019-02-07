#include<iostream>
#include<memory>


class Dog {
	int hair[1000000000L];
	static std::new_handler origHandler;
public:
	static void OutOfMem(){
		std::cerr << "No more memory available\n";
		throw std::bad_alloc();
	}

	void* operator new(std::size_t size) throw (std::bad_alloc) {
		origHandler = std::set_new_handler(OutOfMem);
		void *vp = ::operator new(size);		//What happed if new failed??
		std::set_new_handler(origHandler);		//Restore original handler
		return vp;
	}
};

int main() {
	
	std::tr1::shared_ptr<Dog> pd(new Dog);
}