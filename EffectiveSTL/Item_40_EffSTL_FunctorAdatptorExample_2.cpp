#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

template<typename arg,typename result>
result isEven1(const arg &x) {
	return x % 2 == 1;
}



//bool isEven1(const int &x) {
//	return x % 2 == 1;
//}
class isEven2 :public unary_function<int, bool> {
public:
	bool operator()(const int &x) {
		return x % 2 == 1;
	}
};

void showEle(const int &x) {
	cout << x << " ";
}


struct IsOdd:public unary_function<const int& ,bool > {
	bool operator() (const int& x) const { return x % 2 == 1; }
	//typedef int argument_type;
};


struct IsOdd  {
	bool operator() (const int& x) const { return x % 2 == 1; }
	//typedef int argument_type;
};

int main() {

	vector<int>v = { 1,2,3,4,5,6,7,8,9,10 };
	//v.erase(remove_if(v.begin(), v.end(), not1(isEven2())), v.end());
	//v.erase(remove_if(v.begin(), v.end(), not1(isEven1)), v.end());
	//v.erase(remove_if(v.begin(), v.end(), not1(ptr_fun(isEven1))), v.end());
	//v.erase(remove_if(v.begin(), v.end(), ptr_fun<const int &,bool>(isEven1)), v.end());	
	//for_each(v.begin(), v.end(), showEle);



	
	int values[] = { 1,2,3,4,5 };
	int cx = std::count_if(values, values + 5, std::not1(IsOdd()));
	std::cout << "There are " << cx << " elements with even values.\n";





	getchar();
	return 0;

}