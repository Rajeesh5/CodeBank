#include<iostream>
#include<string>

class Widget {

public:
	Widget(const char* nm) {
		len = strlen(nm);
		m_pName = new char[len + 1];
		memcpy(m_pName, nm, len);
		m_pName[len] = '\0';
			
	}
	Widget(const Widget &rhs) {
	
		m_pName = new char[len + 1];
		memcpy(m_pName, rhs.m_pName, len);
		m_pName[len] = '\0';
	}

	/*
	//unsafe
	Widget& operator=(const Widget &rhs) {

		delete m_pName;						//Deleting it without self assignment check
		m_pName = new char[len + 1];		//Inside the method we can access the m_pName directly.
		memcpy(m_pName, rhs.m_pName, len);
		m_pName[len] = '\0';
		return *this;
	}
	

	
	//self assigmnet safe, but not exception safe
	Widget& operator=(const Widget &rhs) {

		if (this == &rhs)return *this;

		delete m_pName;
		len = rhs.len;
		m_pName = new char[len + 1];				//Suppose exeception is happing over this line (inside new),
													//then no memory allocated. Till now we had deleted this->m_pName 
													//and for self assignment both this and rhs are same.

		memcpy(m_pName, rhs.m_pName, len);			//rhs.name is invalid now, if exection happen with self
													//assignment object.
		m_pName[len] = '\0';
		
		return *this;

	}
	*/

	//Both self assigmnet and exception safe
	Widget& operator=(const Widget &rhs) {

		char *tmp = m_pName;
		len = rhs.len;
		m_pName = new char[len + 1];			//suppose operator new had failed, no mem allocated but still no 
												//change in m_pName.

		memcpy(m_pName, rhs.m_pName, len);		

		delete tmp;								//safe to delete.
		return *this;
	}
	
	const char * getName() const{
		return m_pName;
	}

private:
	char *m_pName;
	int len;
};

void display(const Widget &w) {
	const char *ptr= w.getName();		//Cant access the m_pName;
	std::cout << ptr << "\n";
}


int main_11() {

	Widget w1("Tempreture sensor");
	Widget w2("Pressure Sensor");
	w1 = w1;
	display(w1);

	w1 = w2;
	display(w1);


	getchar();
	return 0;
}