#include<iostream>
#include<vector>
#include<algorithm>

class IncrementFunctor {
public:
	IncrementFunctor() :num(0){}
	void operator() (int &x){
		 x=num+x;
		 num++;
	}
	int num;
};


void IncrementFunction(int &x){
	int num = 0;
	x = num + x;
	num++;
}


void showEle(int x) {
	std::cout << x << ",";
}

int main() {

	std::vector<int>v = { 1,2,3,4,5,6,7,8,9 };

	std::for_each(v.begin(), v.end(), IncrementFunctor());
	std::for_each(v.begin(), v.end(), showEle);



	getchar();
	return 0;
}





