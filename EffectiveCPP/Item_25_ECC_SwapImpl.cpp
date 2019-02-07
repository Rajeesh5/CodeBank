#include<iostream>


class WidgetImpl {
public:
	WidgetImpl():a(0),b(0),c(0) {}
	WidgetImpl(int x, int y, int z) :a(x), b(y), c(z) {}
private:
	int a, b, c;
};

class Widget {
public:
	Widget(int x, int y, int z) {
		impl = new WidgetImpl(x, y, z);
	}
	Widget(const Widget &rhs){
		impl = new WidgetImpl;
		impl = rhs.impl;
	}
	Widget& operator =(const Widget &rhs) {

		if (this == &rhs) return *this;
		delete impl;
		impl = new WidgetImpl;
		impl = rhs.impl;
		return *this;

	}

	void swap(Widget& other)
	{
		using std::swap;
		std::cout << "Inside member swap\n";
		swap(impl, other.impl); // to swap Widgets, swap their
	} // pImpl pointers

	~Widget() {
		delete impl;
	}

private:
	WidgetImpl *impl;
};


namespace std {

	template<> // typical implementation of std::swap;
	void swap<Widget>(Widget& a, Widget& b) // swaps a’s and b’s values
	{
		cout << "Inside non-member std::swap Widget version\n";
		a.swap(b);
	}

}
int main() {

	Widget w1(10, 20, 30),w2(100,200,300);

	//w1 = w2;

	w1.swap(w2);



	getchar();
	return 0;
}

