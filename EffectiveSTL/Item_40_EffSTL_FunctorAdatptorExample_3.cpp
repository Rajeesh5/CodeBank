#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

class Widget {
public:
	int id;
};

struct WidgetIdCompare :public binary_function<Widget&, Widget&, bool> {
	/*
	bool opeartor()(Widget& w1, Widget& w2){
		return (w1.id < w2.id);
	}
	*/

	bool operator()(int x,int y){}

	Widget w1;
	bool opeator() (Widget &w1)
};


int main() {

	return 0;
}