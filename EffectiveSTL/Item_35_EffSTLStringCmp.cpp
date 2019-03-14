#include<iostream>
#include<cctype>
#include<set>
#include<string>
#include<algorithm>

int CharCompair(char ch1, char ch2) {

	int t1 = toupper(static_cast<unsigned int>(ch1));
	int t2 = toupper(static_cast<unsigned int>(ch2));
	if (t1 < t2) {
		return -1;
	}
	else if (t1 < t2) {
		return 1;
	}
	else {
		return 0;
	}
}



int strCompair(const std::string &str1, const std::string &str2) {
	return _stricmp(str1.c_str(), str2.c_str());
}


class StrCopmare {
public:


//	int ciStringCompareImpl(const std::string& s1, const std::string& s2) {
	int operator() (const std::string& s1, const std::string& s2) {
		int str1Size = s1.size();
		int str2Size = s2.size();
		if (str1Size != str2Size)return 1;
		else {
			int init = 0;
			while (init < str1Size) {
				int t1 = toupper(static_cast<unsigned int>(s1[init]));
				int t2 = toupper(static_cast<unsigned int>(s2[init]));
				if (t1 == t2)
					init++;
				else {
					return 1;
				}
			}
		}
		return 0;
		//std::pair<std::string::const_iterator, std::string::const_iterator> poIter;	//Pair of Iterator.
	}

};
/*

int ciStringCompare(const std::string& s1, const std::string& s2)
{
	if (s1.size() >= s2.size()) return ciStringCompareImpl(s1, s2);
	else return -ciStringCompareImpl(s2, s1);
}

*/


void displayEle(const std::string &str)	{
	std::cout << str.c_str();
}

int main() {

	
	//std::cout << CharCompair('A', 'a') << "\n";
	//std::cout << ciStringCompare("Rajeevkumar", "RAjeevKUMAr") << "\n";

	std::set<std::string, StrCopmare> sStr;
	
	sStr.insert("Rajeev");
	sStr.insert("One");
	sStr.insert("Two");


	for_each(sStr.begin(), sStr.end(), displayEle);



	getchar();
	return 0;
}