

#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<functional>


using namespace std;

//case-insensitively compare chars c1 and c2, returning - 1 if c1 < c2,
//0 if c1 == c2, and 1 if c1 > c2
int ciCharCompare(char c1, char c2) {

	int Ic1 = tolower(static_cast<unsigned char>(c1));
	int Ic2 = tolower(static_cast<unsigned char>(c2));
	if (Ic1 < Ic2) return -1;
	if (Ic1 > Ic2) return 1;
	return 0;
}

int ciStringCompareImpl(const string& s1, const string& s2)
{
	// PSCI = "pair of string::const_iterator"
	typedef pair<string::const_iterator, string::const_iterator> PSCI;
	PSCI p = mismatch(s1.begin(), s1.end(), s2.begin(), not2(ptr_fun(ciCharCompare)));

	//if true, either s1 and s2 are equal or s1 is shorter than s2.
	if (p.first == s1.end()) {
		if (p.second == s2.end()) return 0;
		else return -1;
	}
	//the relationship of the strings is the same as that of the mismatched chars
	return ciCharCompare(*p.first, *p.second);
}

struct ciStringCompare :public binary_function<string, string, bool>{
	bool operator()(const string& s1, const string &s2) {
		bool ans;
		if (s1.size() <= s2.size()) 
			ans=ciStringCompareImpl(s1, s2);
		else 
			ans= -ciStringCompareImpl(s2, s1);

		return ans;
	}
};


/*
bool ciStringCompare(const string& s1, const string &s2) {
		if (s1.size() <= s2.size()) return ciStringCompareImpl(s1, s2);
		else return -ciStringCompareImpl(s2, s1);
}


bool ciCharLess(char c1, char c2) {
	return tolower(static_cast<unsigned char> (c1)) <
		tolower(static_cast<unsigned char> (c2));
}



struct ciStringCompare :public binary_function<string, string, bool> {
	bool operator()(const string& s1, const string &s2) {
		//return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(), ciCharLess);
		return _stricmp(s1.c_str(), s2.c_str());
	}
};

*/



void showEle(const string &s) {
	cout << s.c_str() << "\n";
}
int main() {

	set<string, ciStringCompare> strSet;


	strSet.insert("abc");
	strSet.insert("abC");
	strSet.insert("aBc");
	strSet.insert("xyz");

	for_each(strSet.begin(), strSet.end(), showEle);


	getchar();
	return 0;
}