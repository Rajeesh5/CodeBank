#include<iostream>



class Transaction { 								// Base class for all transactions
public:
	Transaction() {
		logTransaction();							//virtual function called from constructor
		std::cout << "Trx created::\n";
	}
	virtual void logTransaction() const = 0; 		// make type-dependent log entry
	
};

void Transaction::logTransaction()const {
	std::cout << "Trx\n";
}


class BuyTransaction : public Transaction { 		// derived class
public:
	virtual void logTransaction() const {		    // how to log transactions of this type
		std::cout << "Buy Trx\n";
	}
};

class SellTransaction : public Transaction { 		// derived class
public:
	virtual void logTransaction() const { 			// how to log transactions of this type
		std::cout << "Sell Trx\n";
	}
};



/*
class Transaction { 								// Base class for all transactions
public:
	Transaction() {
		init();										//virtual function called from constructor
		std::cout << "Trx created::\n";
	}
	virtual void logTransaction() const = 0; 		// make type-dependent log entry

private:
	void init() {
		logTransaction();
	}

};

void Transaction::logTransaction()const {
	std::cout << "Trx\n";                   
}


class BuyTransaction : public Transaction { 		// derived class
public:
	virtual void logTransaction() const {		    // how to log transactions of this type
		std::cout << "Buy Trx\n";
	}
};

class SellTransaction : public Transaction { 		// derived class
public:
	virtual void logTransaction() const { 			// how to log transactions of this type
		std::cout << "Sell Trx\n";
	}
};

*/
int main_9() {


	//Transaction t;


	BuyTransaction b;


	getchar();
	return 0;
}