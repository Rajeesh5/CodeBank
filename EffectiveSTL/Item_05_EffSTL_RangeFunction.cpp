#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Widget {
	string name;
	int id;
public:
	Widget(string _nm,int _id):name(_nm),id(_id){}
	Widget(const Widget& widget):name(widget.name),id(widget.id){
	
		cout << "Copy cons called\n";
	}
	Widget& operator=(const Widget& widget) {

		if (this == &widget)
			return *this;
		name = widget.name;
		id = widget.id;

		cout << "assignment overload called\n";
		return *this;
	}

	//~Widget() {
	//	cout << "distroy\n";
	//}
};




int main() {
	{
		Widget w1("Laptop", 10);
		Widget w2("Watch", 20);
		Widget w3("Tablet", 30);
		Widget w4("Mouse", 40);
		Widget w5("Pendrive", 50);
		Widget w6("KeyBoard", 60);
		Widget w7("Camera", 70);
		Widget w8("Bluetooth", 80);
		Widget w9("Mobile", 90);
		Widget w10("Ipad", 100);


		vector<Widget> wv;
		wv.reserve(10);

		wv.push_back(w1);
		wv.push_back(w2);
		wv.push_back(w3);
		wv.push_back(w4);
		wv.push_back(w5);
		wv.push_back(w6);
		wv.push_back(w7);
		wv.push_back(w8);
		wv.push_back(w9);
		wv.push_back(w10);

		vector<Widget> wv1;
		wv1.reserve(10);

		//wv1.assign(wv.begin() + wv.size() / 2, wv.end());

		wv1[0] = wv[0];




	}
	getchar();
	return 0;
}
