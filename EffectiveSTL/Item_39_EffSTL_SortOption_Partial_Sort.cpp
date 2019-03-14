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
	vector<int> v = { 1, 3, 1, 10, 3, 3, 7, 7, -1 };

	vector<int>::iterator ip;

	// Using std::partial_sort 
	std::partial_sort(v.begin(), v.begin() + 3, v.end());

	// Displaying the vector after applying 
	// std::partial_sort 
	for (ip = v.begin(); ip != v.end(); ++ip) {
		cout << *ip << " ";
	}

	std::partial_sort(v.begin(), v.begin() + v.size(), v.end(),GreaterThen());


	cout << "\n";
	for (ip = v.begin(); ip != v.end(); ++ip) {
		cout << *ip << " ";
	}












	getchar();
	return 0;
}