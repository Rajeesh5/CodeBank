#include<iostream>

using namespace std;


class Widget { 
public:

	virtual void display() {
		cout << "I am Widget display\n";
	}

};
class SpecialWidget : public Widget { 
public:
	void display() {
		cout << "I am spacial Widget display\n";
	}
};
void update(SpecialWidget *psw) {
	psw->display();
}

int main() {

	SpecialWidget *spw;
	Widget *pw;
	pw = new SpecialWidget();
	//update(pw);   //Error! cont convert Widget* to SpacialWidget*, even pw has object of type SpacialWidget
					//internally. but compile time it seems like widget*

	spw = dynamic_cast<SpecialWidget*>(pw);
	update(spw);	//fine.Dynamic_cast is used to perform safe casts down or 
					//across an inheritance hierarchy

	delete pw;

	pw = new Widget;	
	spw = dynamic_cast<SpecialWidget*>(pw);	//Unsuccesfull cast
	if (spw) {
		cout << "cast successfull\n";
		update(spw);			
	}



	getchar();
	return 0;

}