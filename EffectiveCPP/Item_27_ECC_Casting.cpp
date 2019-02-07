#include<iostream>
#include<vector>
#include<memory>

class Widget {
public:
	explicit Widget(int x):m_x(x){}
	//Widget(int x) :m_x(x) {}
private:
	int m_x;
};

void doSomeWork(const Widget& w) {

}

class Window {									// base class
public:
	Window() :state(true){}
	virtual void onResize() { 
		std::cout << "Window resized\n";
		state = false;
	} 
private:
	bool state;
};

class SpecialWindow : public Window { // derived class
public:
	virtual void onResize() {
		
		static_cast<Window>(*this).onResize();
		//Window::onResize();
		
		std::cout << "Spacial windows resize\n";
			
	}
};


int main() {

	doSomeWork(static_cast<Widget>(15));


	Window *w;

	SpecialWindow sw;
	sw.onResize();




	typedef std::vector<std::shared_ptr<SpecialWindow*>> VPSW;

	VPSW winPtrs;

	winPtrs.push_back(new SpecialWindow());


	/*
	//w = &sw;
	w = static_cast<Window*>(&sw);
	
	w->onResize();
	*/
	getchar();
	return 0;
}