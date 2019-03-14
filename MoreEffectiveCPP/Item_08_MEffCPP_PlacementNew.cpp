#include<iostream>

using namespace std;

class Widget {
public:
	Widget(int widgetId):id(widgetId){}
	static Widget * constructWidgetInBuffer(void*, int);
	static void * operator new(size_t, void *location) throw (std::bad_alloc){		
		//Placement new.
		//The purpose of this operator new is to find memory for an object 
		//and return a pointer to that memory.In the case of placement new,
		//the caller already knows what the pointer to the memory should be.

		std::cout << "Placement new Called\n";
		return location;
	}

	static void operator delete(void *vptr,std::size_t size) throw() {	
		cout << "Operator delete called\n";
		if (vptr) {
			free(vptr);		//Because mem allocated by malloc. 
							//use ::operator delete(vptr); if allocated 
							//by ::operator new()
		}
	}

	void display() {
		std::cout << "Widget ID::" << id << endl;;
	}
private:
	int id;
};


Widget* Widget::constructWidgetInBuffer(void *buffer,	int widgetId)
{
	return new (buffer) Widget(widgetId);
}


int main() {

	void *rawMem = malloc(sizeof(Widget));
	Widget::constructWidgetInBuffer(rawMem, 1001);

	Widget *widget = static_cast<Widget*>(rawMem);
	widget->display();

	delete widget;

	getchar();
	return 0;
}

