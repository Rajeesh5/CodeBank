#include<iostream>

template<typename T>
class Array {
public:
	struct ArraySize {
		ArraySize(int noOfEle):theSize(noOfEle) {		}
		int size() { return theSize; }
		int theSize;
	};

	Array(int lowB,int highB){}
	bool operator==(const Array &rhs){}
	Array(ArraySize size){}
};


int main() {

	Array<int> a1(10);


	getchar();
	return 0;
}

