#include<iostream>
#include<new>

//function to call if operator new can’t allocate enough memory
void outOfMem() {
	std::cerr << "Unable to satisfy request for memory\n";
	std::abort();
}

class Widget {
public:
	static std::new_handler set_new_handler(std::new_handler p) throw();
	static void* operator new(std::size_t size) throw(std::bad_alloc);
private:
	static std::new_handler currentHandler;
};

std::new_handler Widget::currentHandler = 0;

class NewHandlerHolder {
public:
	// acquire current new-handler
	explicit NewHandlerHolder(std::new_handler nh) : handler(nh) {}
	~NewHandlerHolder() { 							// release it
		std::set_new_handler(handler);
	}
private:
	std::new_handler handler; 							// remember it
	NewHandlerHolder(const NewHandlerHolder&); 			// prevent copying
	NewHandlerHolder& operator=(const NewHandlerHolder&);
};



void* Widget::operator new(std::size_t size) throw(std::bad_alloc)
{
	// install Widget’s new-handler
	NewHandlerHolder h(std::set_new_handler(currentHandler));  
	return ::operator new(size); 			// allocate memory or throw
}											// restore global new-handler.





std::new_handler Widget::set_new_handler(std::new_handler p) throw()
{
	std::new_handler oldHandler = currentHandler;
	currentHandler = p;
	return oldHandler;
}


int main() {

	Widget::set_new_handler(outOfMem); 		// set outOfMem as Widget’s new-handling  function
	Widget *pw1 = new Widget; 				// if memory allocation fails, call outOfMem
	std::string *ps = new std::string; 		// if memory allocation fails, call the global new-
											// handling function (if there is one)
	Widget::set_new_handler(0); 			// set the Widget-specific new-handling function to nothing (i.e., null)
	Widget *pw2 = new Widget;			    // if mem. alloc. fails, throw an exception immediately. (There is no new- handling 
											// function for class Widget.
	
	getchar();
	return 0;
}