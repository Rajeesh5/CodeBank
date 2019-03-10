#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


bool isEqual(const int &x, const int &y) {
	if (x == y)return true;
	else return false;

}

int main() {

	vector<int> v1 = { 1, 10, 15, 20};
	vector<int> v2 = { 1, 10, 15, 20, 45 };

	pair<vector<int>::iterator, vector<int>::iterator> pi;

	pi = mismatch(v1.begin(), v1.end(), v2.begin(), isEqual);
	//pi = mismatch(v1.begin(), v1.end(), v2.begin());


	//cout << *pi.first << "\n";   //Not derefrencable *pi.first pointes to the end()
	//cout << *pi.second << "\n";		//Points to 45.

	if (pi.first == v1.end())
	{
		cout << "Vector v1 is totally consumed\n";

		if (pi.second == v2.end()) {
			cout << "vector v2 is totally consumed, So both are equal\n";
		}
		else
		{
			cout << "vector v1 & v2 are uneual( v1 < v2)\n";
		}
	}

	getchar();
	return 0;
}