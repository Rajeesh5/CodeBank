#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>

using namespace std;

template<typename arg, typename result>
class custom_pointer_to_unary_func:public unary_function<arg,result>{
	result(*fun_ptr)(arg);
public:

	custom_pointer_to_unary_func(result(*tmp)(arg)):fun_ptr(tmp){}
	result opeartor(arg x) {
		return fun_ptr(x);
	}

};

template<typename arg,typename result>
custom_pointer_to_unary_func custom_ptr_fun(result (*fun_ptr) (arg)) {
	return custom_pointer_to_unary_func<arg, result>(fun_ptr);
}



int main() {


	double numbers[] = { 10.0, 20.0, 40.0, 80.0, 160.0 };
	double logs[5];
	transform(numbers, numbers + 5, logs, custom_ptr_fun<double,double>(log));
	for (int i = 0; i<5; i++)
		cout << logs[i] << " ";
	cout << endl;

	getchar();
	return 0;
}

