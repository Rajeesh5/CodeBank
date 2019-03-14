#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

//for_each decleration;

//template<typename Inputlterator, typename Function>
//Function for_each(Inputlterator first, Inputlterator last, Function f);





class DoSomething :	public unary_function<int, void> { 
public:
	void operator()(int x) { 

		std::cout << x << "\n";
	//	return (x % 2 == 0); 
	}

};



int main() {


	typedef deque<int>::iterator DequeIntIter;		// Deque Iterator
	deque<int> di;
	DoSomething d;									// create a function object
	
	di.push_back(10);
	di.push_back(20);
	di.push_back(30);
	di.push_back(40);
	di.push_back(50);
	di.push_back(60);
		
	for_each<DequeIntIter,							// call for_each with type
				DoSomething&>(	di.begin(),			// parameters of DequeIntIter
								di.end(),			// and DoSomething&;
								d
							);						// this forces d to be passed and returned by reference



	getchar();
	return 0;


}