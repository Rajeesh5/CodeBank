#include<iostream>


void logCall(const std::string& funcName) {
	std::cout << funcName.c_str() << "\n";
}

class Customer {
public:
	//Customer() {}
	Customer(const std::string str):name(str) {

	}

	Customer(const Customer& rhs):name(rhs.name) {
		logCall("Customer copy constructor");
	}
	Customer& operator=(const Customer& rhs) {
		logCall("Customer copy assignment operator");
		name = rhs.name;								// copy rhs’s data
		return *this;
	}
	
private:
	std::string name;
};


class PriorityCustomer : public Customer { // a derived class
public:
	/*
	
	//Below copy ctor not compile, It will ask about the base class defalut ctor
	//which we have dont created.
	
	PriorityCustomer(const PriorityCustomer& rhs):priority(rhs.priority){
		logCall("PriorityCustomer copy constructor");
	}
	

	
	//This assignment overload missed base class member copy.
	PriorityCustomer& operator=(const PriorityCustomer& rhs) {
		logCall("PriorityCustomer copy assignment operator");
		priority = rhs.priority;
		return *this;
	}
	
	*/
	PriorityCustomer(const PriorityCustomer& rhs)	: Customer(rhs), // invoke base class copy ctor
		priority(rhs.priority)
	{
		logCall("PriorityCustomer copy constructor");
	}

	PriorityCustomer& operator=(const PriorityCustomer& rhs)
	{
		logCall("PriorityCustomer copy assignment operator");
		Customer::operator=(rhs);									// assign base class parts
		priority = rhs.priority;
		return *this;
	}


private:
	int priority;
};


int main_12() {
	Customer c1("Rajeev");
	Customer c2("Suresh");




	return 0;
}