#include<iostream>
#include<vector>
#include<algorithm>
#include<list>

using namespace std;

bool isEven(int x) {
	return x % 2 == 0;
}

int main(){
// Initializing vector 
vector<int> vect = { 2, 1, 5, 6, 8, 7 };

bool res=is_partitioned(vect.begin(), vect.end(), isEven);		//false

// partitioning vector using partition() 
partition(vect.begin(), vect.end(), isEven);

// Checking if vector is partitioned  
// using is_partitioned() 
res=is_partitioned(vect.begin(), vect.end(), isEven);			//true


	list<int> lst= { 2, 1, 5, 6, 8, 7 };
	vector<int> tmp(lst.begin(), lst.end());






return 0;

}