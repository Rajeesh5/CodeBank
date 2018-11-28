#include<iostream>

using namespace std;

class RCString
{
private:
	struct StringValue {
		int refCount;
		char *data;
		bool shareable;
		StringValue(const char *initValue);
		~StringValue();
	};
	StringValue *value; // value of this String

public:

	RCString(const char *initValue = "");
	RCString(const RCString& rhs);
	RCString& operator=(const RCString& rhs);
	char& operator[](int index)const;				//For Const String
	char& operator[](int index);					//For non-Const String.


	~RCString();
	void showStr()const {
		cout << "Data:: " << value->data << ", Address::" << &(value->data) << endl;
		cout << "Ref cnt:: " << value->refCount << endl;
		cout << "---------------\n";
	}
};


char& RCString::operator[](int index)const
{
	if ((strlen(value->data) - 1) > index)
		return value->data[index];
	
}

char& RCString::operator[](int index) 
{


	if (value->refCount > 1) {
		--value->refCount;
		value = new StringValue(value->data);
	}
	value->shareable = false; 
	return value->data[index];
}

RCString& RCString::operator=(const RCString& rhs)
{
	if (this->value == rhs.value)
		return *this;

	this->~RCString();
	this->value = rhs.value;
	this->value->refCount++;
	return *this;
}

RCString::~RCString()
{
	if ((--value->refCount) == 0) {
		value->~StringValue();
	}
}

RCString::RCString(const char *initValue) : value(new StringValue(initValue))
{
}

RCString::RCString(const RCString& rhs) {

	if (rhs.value->shareable) {
		value = rhs.value;
		++value->refCount;
	}
	else {
		value = new StringValue(rhs.value->data);
	}
	
}

RCString::StringValue::StringValue(const char *initValue) : refCount(1),shareable(true) {
	data = new char[strlen(initValue) + 1];
	strcpy(data, initValue);
}

RCString::StringValue::~StringValue() {
	delete[] data;
}



int main() {


	RCString str3("RajeevKumarNayan");
	RCString str4(str3);

	cout << str3[0] << endl;  //Read, Unfortunately in operator[] call, we canot determine        
							  //whether it is called by read or write operation.
	str3.showStr();			  //str3->refCount=1
	str4.showStr();			  //str4->refCount=1
							  //Still having seperate copy of string "RajeevKumarNayan" which is ellogical

	RCString str5(str4);
	str5.showStr();


	RCString str6(str3);
	str6.showStr();


	getchar();
	return 0;

}