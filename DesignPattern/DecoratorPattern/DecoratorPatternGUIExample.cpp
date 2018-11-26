#include<iostream>


//Window Interface, Component window
class Window {
public:
	virtual void renderWindow() = 0;
};

//Window implementation,Concrete implementation

class SimpleWindow:public Window {
public:
	void renderWindow() {
		// implementation of rendering details
		std::cout << "Simple windows Rendering";
	}
};

class DecoratedWindow: public Window {

public:
	DecoratedWindow(Window *ref):WindowRef(ref){}
	void renderWindow() {
	
		WindowRef->renderWindow();
	}
private:
	Window *WindowRef;


	

	/*
	//protected reference to the window being decorated
protected:
	Window *WindowRef;
	*/
};


// Concrete Decorator with extended state
// Scrollable window creates a window that is scrollable

class ScrollableWindow :public DecoratedWindow {

public:
	ScrollableWindow(Window *ref) :DecoratedWindow(ref) {}

	void renderWindow() {

		// render scroll bar 
		renderScrollBarObject();

		// render decorated window
		DecoratedWindow::renderWindow();
	}

private:
	void renderScrollBarObject() {

		// prepare scroll bar like.
		// ScrollBar *scr= new ScrollBar();
		// add ScrollBar component into Window, i,e windows now decoreted with scrollbar
		// WindowRef->addComponect(scr);
		std::cout << "Decorated with scrollBar ";

	}
};

/*
class ScrollableWindow:public DecoratedWindow {

public:
	ScrollableWindow(Window *ref) {
		WindowRef = ref;
	}
	void renderWindow() {

		// render scroll bar 
		renderScrollBarObject();

		// render decorated window
		WindowRef->renderWindow();
	}

private:
	void renderScrollBarObject() {

		// prepare scroll bar like.
		// ScrollBar *scr= new ScrollBar();
		// add ScrollBar component into Window, i,e windows now decoreted with scrollbar
		// WindowRef->addComponect(scr);
		std::cout << "Decorated with scrollBar ";

	}	
};

*/
int main() {


	Window *window = new SimpleWindow();
	window->renderWindow();

	// at some point later 
	// maybe text size becomes larger than the window 
	// thus the scrolling behavior must be added 

	// decorate old window 

	std::cout << "\n";
	window = new ScrollableWindow(window);

	// now window object 
	// has additional behavior / state 

	window->renderWindow();

	getchar();
	return 0;
}