#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;


struct GreaterThen :public binary_function<int, int, bool> {
	bool operator()(int x, int y) {
		return x > y;
	}

};


int main()
{
	//vector<int> v = { 3, 2, 10, 45, 33, 56, 23, 47 };

	//vector<int>::iterator ip;
	//nth_element(v.begin(), v.begin() + 4, v.end());


	int v[] = { 3, 2, 10, 45, 33, 56, 23, 47 }, i;

	// Using std::nth_element with n as 5 
	std::nth_element(v, v + 4, v + 8);


	for (i = 0; i < 8; ++i) {
		cout << v[i] << " ";
	}



	//cout << "\n";
	//for (ip = v.begin(); ip != v.end(); ++ip) {
	//	cout << *ip << " ";
	//}



	getchar();
	return 0;
}