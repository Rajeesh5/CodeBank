#include<iostream>

using namespace std;


struct StringValue {
	int refCount;
	char *data;
	int index;
	StringValue(const char *initValue, int index = 0);
	~StringValue();

	char& operator=(char c)					// lvalues uses
	{
		this->refCount--;
		return data[index];

	}
	operator char() const					// rvalues uses
	{
		return data[index];
	}
};

class RCString
{
private:

	StringValue *value; // value of this String

public:

	RCString(const char *initValue = "");
	RCString(const RCString& rhs);
	RCString& operator=(const RCString& rhs);
	char& operator[](int index);					


	~RCString();
	void showStr()const {
		cout << "Data:: " << value->data << endl;
		cout << "Ref cnt:: " << value->refCount << endl;
		cout << "---------------\n";
	}
};



char& RCString::operator[] (int index) //throw ArrayOutOfBoundExeception,Implement leter..
{
	//return  StringValue(value->data,index);	
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
	if ((--value->refCount) == 0) 
		value->~StringValue();
}

RCString::RCString(const char *initValue) : value(new StringValue(initValue))
{
}

RCString::RCString(const RCString& rhs) : value(rhs.value) {

	++value->refCount;
}

StringValue::StringValue(const char *initValue,int index) : refCount(1) {
	data = new char[strlen(initValue) + 1];
	strcpy(data, initValue);
	this->index = index;
}

StringValue::~StringValue() {
	delete[] data;
}



int main() {
	
	{


		RCString str1("RajeevKumarSharma");
		RCString str2(str1);

		//str2 = "xyx";

		cout << str1[3] << endl;

		//str2[1] = 'X';

		str1.showStr();
		str2.showStr();

	}
	getchar();
}