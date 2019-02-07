#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void showVectEle(int x) {
	cout << x<<",";
}

bool isEven(int x) {
	return (x % 2 == 0);
}


int main() {
	vector<int> v = { 1,2,3,2,5,6,2,8,9,10 };

	
	remove(v.begin(), v.end(), 2);

	for_each(v.begin(), v.end(), showVectEle);	//output-1,3,5,6,8,9,10,8,9,10

	cout << endl << v.size() << endl;			//size=10
	cout << v.capacity() << endl;				//capacity=10;

	//When add next element capacity will increase by 10/2 i,e = 15	 (n+n/2)

	
	//for complete remove follow erase-remove idiom.
	//the best way to get rid of elements with a specific value when container
	//is a vector,string, or deque.

	//for list erase is enough, for ex- lst.remove(1963);

		
	v.erase(remove(v.begin(), v.end(), 10), v.end());
	for_each(v.begin(), v.end(), showVectEle);	//output output-1,3,5,6,8,9

	
	//When c is a standard associative container(i.e..a set.multiset, map. or multimap).
	//Such containers have no member function named remove.

	//c.erase(1963);  best way to get rid of elements with a specific value when c is a
	//standard associative container


	//How to remove multiple value for std seq container.
	//remove all even number form vector.

	v.erase(remove_if(v.begin(), v.end(), isEven), v.end());

	cout << endl;
	for_each(v.begin(), v.end(), showVectEle);

	//same applicable for vector, string, deque but list: c.remove_if(isEven);


	//If the container is a standard associative container, use remove_copy_if and
	//swap, or write a loop to walk the container elements, being sure to
	//postincrement your iterator when you pass it to erase.

	





	getchar();
	return 0;

}