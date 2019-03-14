#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Widget {
	string name;
	int id;
public:
	Widget():name("Un-named"),id(0){}
	Widget(string _nm, int _id) :name(_nm), id(_id) {}
	Widget(const Widget& widget) :name(widget.name), id(widget.id) {
		cout << "Copy cons called\n";
	}
	~Widget() {
		cout << "distroy\n";
	}

	string getName() { return name; }
	int getId() { return id; }
};

void display(Widget &w) {
	cout << "Widget Nm::" << w.getName().c_str() << "ID::" << w.getId() << endl;
}

int main() {

	vector<Widget> v;
	v.reserve(5);

	cout << v.size() << endl;		//size- 0, no object.
	cout << v.capacity() << endl;	//capacity -5

	Widget w1("Laptop", 10);
	Widget w2("Watch", 20);
	Widget w3("Tablet", 30);

	v.push_back(w1);
	v.push_back(w2);
	v.push_back(w3);

	cout << "Capacity remains" << v.capacity() - v.size() << endl;	//2 extra element hold by container.

	cout << "Re-sized by 10\n"; 
	//Resize the vector. delete the old entry, make big size then copy it.
	//for rest call default copy ctor.

	v.resize(10);

	for_each(v.begin(), v.end(), display);		//3- Widget, 7-default Widget.

	v.resize(5);
	
	//5- widget distroy.

	cout << v.size();				//Size-5
	cout << v.capacity();			//capacity-10

	getchar();
	return 0;
}