#include<iostream>


template<typename T>
class NamedObject {
public:
	NamedObject(std::string& name, const T& value):nameValue(name),objectValue(value){}
	
		// as above, assume no operator= is declared
private:
	std::string& nameValue; 				// this is now a reference
	const T objectValue; 					// this is now const
};


class EmptyRef {
	int &x;
public:
	EmptyRef(int _x):x(_x){}
	EmptyRef& operator=(const EmptyRef &e) {
		*this = e;
		return *this;
	}
};


class EmptyConst {
	const int x;
public:
	EmptyConst(int _x) :x(_x) {}
	
	EmptyConst& operator=(EmptyConst &e) {
		//x = e.x;
		return *this;
	}
	
};


int main() {

	EmptyConst ec1(10), ec2(20);

	ec1 = ec2;			//Error. if donot define custom operator = overload.

	EmptyRef e1(0), e2(1);
	e1 = e2;             //Error. if donot define custom operator = overload.

	//Now consider what should happen here :

	std::string newDog("Persephone");
	std::string oldDog("Satch");
	NamedObject<int> p(newDog, 2);                               // when I originally wrote this, our dog Persephone was 
																 //about to have her second birthday

	NamedObject<int> s(oldDog, 36);								// the family dog Satch (from my childhood) would be 36 if 
																// she were still alive

	//p = s;



	/*
	std::string s1("Nancy");
	std::string s2("Clancy");
	std::string& rs = s1; 			// rs refers to s1
	std::string *ps = &s1; 			// ps points to s1
	rs = s2;						// rs still refers to s1, but s1's value is now "Clancy"
	ps = &s2; 						// ps now points to s2; s1 is unchanged

	*/


	getchar();
	return 0;


}