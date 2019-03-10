#include<iostream>
#include<set>
#include<string>

using namespace std;

class StringPtrLess {
public:
	bool operator()(const string *lsh, const string *rhs)const {
		return *lsh < *rhs;
	}
};

struct StringPtrLess :public binary_function<string*, string*,bool> {
	bool operator()(const string *lsh, const string *rhs)const {
		return *lsh < *rhs;
	}
};


int main() {

	/*
	set<string*>ssp;	//Set of String pointers.
	ssp.insert(new string("Anteater"));
	ssp.insert(new string("Wombat"));
	ssp.insert(new string("Lemur"));
	ssp.insert(new string("Penguin"));

	//Set not contained sorted string value insted of that 
	//It stored string pointer in sorted order.

	set<string*>::iterator spIter;	//String pointer iterator.

	for (spIter = ssp.begin(); spIter != ssp.end(); ++spIter) {
		cout << "Address::"<<*spIter<<" Value :: "<<**spIter << endl;
	}

	for (spIter = ssp.begin(); spIter != ssp.end(); ++spIter) {
		delete *spIter;
	}
	*/




	set<string*,StringPtrLess>ssp;	//Set of String pointers.
	ssp.insert(new string("Anteater"));
	ssp.insert(new string("Wombat"));
	ssp.insert(new string("Lemur"));
	ssp.insert(new string("Penguin"));

	//Set not contained sorted string value insted of that 
	//It stored string pointer in sorted order.

	set<string*>::iterator spIter;	//String pointer iterator.

	for (spIter = ssp.begin(); spIter != ssp.end(); ++spIter) {
		cout << "Address::" << *spIter << " Value :: " << **spIter << endl;
	}

	for (spIter = ssp.begin(); spIter != ssp.end(); ++spIter) {
		delete *spIter;
	}

	getchar();
	return 0;
}