#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<iterator>
using namespace std;




class Widget{};

class BadPredicate : public unary_function<Widget, bool> { 
public:
	BadPredicate() : timesCalled(0) {} 
	bool operator()(const Widget&)
	{
		return ++timesCalled == 3;
	}
private:
	size_t timesCalled;
};


class IsEven {
public:
	bool operator()(int x)const{
		return x % 2 == 0;
	}
};

void displayEle(int x){
	std::cout << x << ",";
}



/*

template <class ForwardIterator, class UnaryPredicate>
ForwardIterator remove_iff(ForwardIterator first, ForwardIterator last,
	UnaryPredicate pred)
{
	ForwardIterator result = first;
	while (first != last) {
		if (!pred(*first)) {
			*result = *first;
			++result;
		}
		++first;
	}
	return result;
}

*/


template <typename Fwdlterator, typename Predicate>
Fwdlterator remove_iff(Fwdlterator begin, Fwdlterator end, Predicate p)
{
	begin = find_if(begin, end, p);
	if (begin == end) return begin;
	else {
		Fwdlterator next = begin;
		return remove_copy_if(++next, end,begin, p);
	}
}


class BadRemove : public unary_function<Widget, bool> {
public:
	BadRemove() : timesCalled(0) {}
	bool operator()(const int&)
	{
		cout << "number of time::" << timesCalled << "\n";
		return ++timesCalled == 3;
	}
private:
	size_t timesCalled;
};



int main() {
/*
	set<int> sint;

	sint.insert(1);
	sint.insert(2);
	sint.insert(3);
	sint.insert(4);
	sint.insert(5);
	sint.insert(6);
	sint.insert(7);
	sint.insert(8);

	set<int> oddVal;

	remove_copy_if(sint.begin(), sint.end(), inserter(oddVal, oddVal.end()), IsEven());
	

	for_each(sint.begin(), sint.end(), displayEle);
	cout << "\n";
	for_each(oddVal.begin(), oddVal.end(), displayEle);

	sint.swap(oddVal);
	//OR,  sint.swap(oddVal);
	
	cout << "---------------\n";
	for_each(sint.begin(), sint.end(), displayEle);
	cout << "\n";
	for_each(oddVal.begin(), oddVal.end(), displayEle);
	*/

	vector<int> v{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};


	vector<int>::iterator it = find_if(v.begin(), v.end(), BadRemove());

	cout << *it;




	//v.erase(remove_iff(v.begin(), v.end(), BadRemove()),v.end());
	//for_each(v.begin(), v.end(), displayEle);



	/*

	vector<Widget> vw;		// create vector and put some Widgets into it

	//Suppose we use this class to eliminate the third Widget from a vector<Widget> 
	vw.erase(remove_if(vw.begin(), 	vw.end(), BadPredicate()), vw.end());
	*/



	

	getchar();
	return 0;
}