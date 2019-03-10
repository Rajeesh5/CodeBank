#include<iostream>
#include<set>
#include<algorithm>
#include<functional>

using namespace std;



template<typename T>
class LsbLessEq {
public:
	bool operator() (const T x, const T y)const {

		if (x == y) {
			return false;
		}
		else {
			return  (x < y);
		}
	}
};


void print(int x) {
	cout << x << ",";
}
int main() {

	set<int, LsbLessEq<int>> s;

	s.insert(10);
	s.insert(10);
	s.insert(10);
	s.insert(10);
	s.insert(10);

	for_each(s.begin(), s.end(), print);


	return 0;
	getchar();

}
