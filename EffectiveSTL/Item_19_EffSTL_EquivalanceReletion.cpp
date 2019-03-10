#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<functional>


using namespace std;

class LsbLess {
public:
	bool operator() (int x, int y)const {
		return((x % 10) < (y % 10));
	}
};


bool isOdd(int x) {
	return (x % 2 == 1);
}

//case-insensitively compare chars c1 and c2, returning - 1 if c1 < c2,
//0 if c1 == c2, and 1 if c1 > c2
int ciCharCompare(char c1, char c2){							
										
	int Ic1 = tolower(static_cast<unsigned char>(c1));
	int Ic2 = tolower(static_cast<unsigned char>(c2)); 													  
	if (Ic1 < Ic2) return -1;
	if (Ic1 > Ic2) return 1;
	return 0;
}

//int ciStringCompareImpl(const string& s1, const string& s2); 

struct ciStringCompare:public binary_function<string,string,bool>
{
public:

	bool operator()(const string& s1, const string &s2) {
		if (s1.size() <= s2.size()) return ciStringCompareImpl(s1, s2);
		else return -ciStringCompareImpl(s2, s1);
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
};


class CaseLessStrCom {
public:
	bool operator()(std::string &s1, std::string &s2) {

		transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
		transform(s2.begin(), s2.end(), s2.begin(), ::toupper);

		return s1 < s2;
		//if (!strcmp(s1.c_str(), s2.c_str()))
		//	return true;
		//else return false;
		
	}
};





struct CaseLessStrCompare:public binary_function<string,string,bool> {
	bool operator()(const std::string &s1, const std::string &s2) const{
		return _stricmp(s1.c_str(), s2.c_str());
	}
};


class SetEleDisplay
{public:

	void operator ()(const std::string &str) {
		std::cout << str.c_str() << "\n";
	}
};


int main() {

	/*
		-Make a tree like sorted data-structure.
		-Use given comparision method to sort & build the tree.
		-While inserting & finding check for equivalancy( not equality).	
	*/

	std::set<std::string, CaseLessStrCompare> setStr;

	std::set<std::string, ciStringCompare> setStr1;





	setStr1.insert("Rajeev");
	setStr1.insert("vikash");






	//std::set<std::string> setStr;
	//std::pair<std::set<std::string, CaseLessStrCom>::iterator, bool> walker;
	//for_each(setStr.begin(), setStr.end(), SetEleDisplay());


	//std::string s1 = "Rajeev";
	//std::string s2 = "rajeev";

 
	//if (!strcmp(s1.c_str(), s2.c_str()))
	//	std::cout << "String equal\n";
	//else std::cout << "String un-equal\n";


	/*

	std::set<int> set1;

	std::pair<std::set<int>::iterator, bool> ret;

	ret = set1.insert(10);

	if (ret.second == true) {
		std::cout << "Element inserted\n";
		std::cout << *(ret.first) << "\n";
	}







	std::set<int, LsbLess> s = { 21,23,26,27 };
	std::set<int, LsbLess>::iterator iter1,iter2;


	iter1 = find(s.begin(), s.end(), 36);

	if (iter1 == s.end())
		std::cout << "Item not found\n";
	else	
		std::cout << *iter1;
	
	
	iter2 = s.find(36);

	if (iter2 == s.end()) 
		std::cout << "item not found\n";
	else	
		std::cout << *iter2;

	
	ret = s.insert(46);
	if (ret.second == true) {
		std::cout << "Element inserted\n";
		std::cout << *(ret.first) << "\n";
	}
	else {
		std::cout << "Item not inserted\n";
	}


	*/





	getchar();
	return 0;
}

