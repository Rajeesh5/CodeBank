#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

bool isEven(int x) {
	return (x % 2 == 0);
}

int main() {

	vector<int> v;

	for (int i = 0; i < 1000; i++) {
		v.push_back(i);
	}

	cout << "Size::" <<v.size() << "Capacity=" << v.capacity() << endl;

	v.erase(remove_if(v.begin(), v.end(), isEven),v.end());

	cout << "Size::" << v.size() << "Capacity=" << v.capacity() << endl;

	//Now size is 500 and capacity is apx 1000. 
	//How to trim extra capatity.


	vector<int>(v).swap(v);			//tmpVector.swap(v);

	cout << "Size::" << v.size() << "Capacity=" << v.capacity() << endl;



	getchar();
	return 0;
}