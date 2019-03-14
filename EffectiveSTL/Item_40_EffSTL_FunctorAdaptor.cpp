
#include <iostream>     // std::cout
#include <functional>   // std::not1
#include <algorithm>    // std::count_if

struct isOdd1 {
	bool operator() (const int& x) const { return  x % 2 == 1; }
	typedef int argument_type;
};

bool isOdd2(const int &x) {
	return x % 2 == 1;
	typedef int argument_type;
}






int main() {
	int values[] = { 1,2,3,4,5 };

	std::cout<< std::count_if(values, values + 5, isOdd2);		//Odd count using function 
	std::cout<< std::count_if(values, values + 5, isOdd1());	//Odd count using functor


	//std::cout << std::count_if(values, values + 5, std::not1(isOdd2));		//Even count using function 
	std::cout << std::count_if(values, values + 5, std::not1(isOdd1()));	//Even count using functor


	getchar();
	return 0;
}