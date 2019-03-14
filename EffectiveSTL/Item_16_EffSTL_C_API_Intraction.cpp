#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>


using namespace std;


void fillArray(char *cptr, int size) {
	for (int i = 0; i < size; i++)
		cptr[i] = 'a';	
}

int main() {

	vector<char> cv(10);

	fillArray(&cv[0], cv.size());
	string s(cv.begin(), cv.end());

	deque<char> dc(cv.begin(), cv.end());

	
	cout << s.c_str();

	getchar();
	return 0;
}