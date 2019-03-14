#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

template<typename T>
class Less {
public:
	bool operator()(const T x, const T x) {
		return x < y;			//If x == y then return false. 
	}
};

template<typename T>
class LessEq1 {
public:
	bool operator()(const T x, const T x) {
		return x <= y;			//if x==y then return true, which is problematic.
	}
};

template<typename T>
class LessEq2 {
public:
	bool operator()(const T x, const T x) {
		if (x == y)				//Always return false for euqal value.
			return false;
		else return x < y;
	}
};

int main() {

	set<int, Less<int>>s;

	s.insert(10);
	s.insert(5);
	s.insert(2);	
	s.insert(2);	
	
	//This time comparator funtion return false.
	//	!(w1<w2) && !(w2<w1)			Expression used to test equvalancy. Where w1<w2 and
	//									w2<w1 are the boolen output by comparator funtion Less.
	//  !false && !false => true		Which means the '2' which we are going to insert, is 
	//									equivalent to another '2' which is pre-existed in container.

	//Suppose we have another comparator function LessEq1 <=


	set<int, LessEq1<int>> s1;

	s1.insert(10);		//10a
	//s1.insert(10);	//10b			//Now our container will crashed after inserting second copy of 10
	
	//why?
	// This time comparator function LessEq1 return true for equal values
	// !(10 LessEq1 10) && !(10 LessEq1 10)	= false.
	// now the above express output is false which means both copy of 10's are not 
	// equivalent. When it try to insert secnod copy of 10's the container its self
	// currppted, because set only holds the unique value.

	set<int,LessEq2<int>> s2;

	s2.insert(10);
	s2.insert(10);

	//Now LessEq2 gives false for equal values. And expression optput true that means
	//10 is already present in set containter dont add another one.


	//Even in multiset which contains equal value, also compatator function return 
	//false for equal value.

	multiset<int, LessEq1<int>> ms1;
	ms1.insert(10);
	ms1.insert(10);				//Second 10 insertion will currupt the containter. Why??

	//Befor proceding to why above is faild lets consider small example:

	//------------------------------------------------------------------------//
	vector<int> v = { 10, 10, 30, 30, 30, 100, 10,	300, 300, 70, 70, 80 };
	sort(v.begin(), v.end(), Less<int>());		// sort the vector with user defined comparetor function
												// for desending order sort only replace the operator < with op >
	pair<vector<int>::iterator, vector<int>::iterator> piter;
	piter = equal_range(v.begin(), v.end(), 30);

	// Displaying the subrange bounds 
	cout << "10 is present in the sorted vector from index "
		<< (piter.first - v.begin()) << " till " << (piter.second - v.begin());
	//-------------------------------------------------------------------------//

	//Now come to the original problem, why multiset not accepting two copy of same value.
	//Here the comparator funtion return value is true and expression output is false.
	//which means both copy of 10's are not equivalant. Then think how equal_range() method 
	//behave? because equal_range() assume both 10's are same(eqivalant) but contater state that
	//both are difftrent. This is contradistion.


	//Now again we craete multiset with compatator function LessEq2, which return false
	//when both valus are equal, this time it will work.

	multiset<int, LessEq2<int>> ms1;
	ms1.insert(10);
	ms1.insert(10);

	//Moral:: always return false for euqal value form user defined comparator. 


	getchar();
	return 0;
}