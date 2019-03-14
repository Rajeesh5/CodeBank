#include<iostream>

using namespace std;



class RCString
{
private:
	struct StringValue {
		int refCount;
		char *data;
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


//Implementation of the const version of this function is straightforward, because it's a read-only operation; the
//value of the string can't be affected

char& RCString::operator[](int index)const
{
	if ((strlen(value->data) - 1) > index)
		return value->data[index];
	///else throw ArrayOutOfBoundExeception
}

//Non-const version, Since we donot know whether it is read or write, so we are creating new set of stringValue 
//therefor it canot craete problem while write operation happning.

char& RCString::operator[](int index) //throw ArrayOutOfBoundExeception,Implement leter..
{
	// if we're sharing a value with other String objects, break off a separate copy of the value for ourselves
	if (value->refCount > 0)
	{
		// decrement current value's refCount, because we won't be using that value any more
		value->refCount--;
		value = new StringValue(value->data);   // make a copy of the value for ourselves.
	}

	// return a reference to a character inside our unshared StringValue object
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
	if ((--value->refCount) == 0) {			//If ref cnt is Zero
		value->~StringValue();				//then only delete the data.
	}
}

RCString::RCString(const char *initValue) : value(new StringValue(initValue))
{
}

RCString::RCString(const RCString& rhs) : value(rhs.value) {

	++value->refCount;
}

RCString::StringValue::StringValue(const char *initValue) : refCount(1) {
	int size = strlen(initValue);
	data = new char[size + 1];
	memset(data, 0, size + 1);
	memcpy(data, initValue, size);
}

RCString::StringValue::~StringValue() {
	delete[] data;
}



int main_1() {

	{


		RCString str1("Hello!!");
		RCString str2(str1);
		RCString str3(str1);

		RCString str4("Hi:)");
		RCString str5(str4);

		str2 = str4;

		/*

		//Problem with Write operation-When we modify a String's value, we have to be careful to avoid 
		//modifying the value of other String objects.Because we all share same value among classes.
		//And Unfortunately, there is no way for C++ compilers to tell us whether a particular use of 
		//operator[] is for a read or a write.

		//Write Operation

		RCString str1("RajeevKumarSharma");		//str1->refCount=1
		RCString str2(str1);					//str1->refCount=2,str2->refCount=2
												//Both have same copy of string.
		str2[0] = 'X';			//Now we will modifying str2, but It should not be inmpact str1

		str1.showStr();			//str1->refCount=1
		str2.showStr();			//str2->refCount=1,It have seperate copy of string "XajeevKumarSharma"


								//Read Operation.

		RCString str3("RajeevKumarNayan");
		RCString str4(str3);

		cout << str3[0] << endl;  //Read, Unfortunately in operator[] call, we canot determine        
								  //whether it is called by read or write operation.
		str3.showStr();			  //str3->refCount=1
		str4.showStr();			  //str4->refCount=1
								  //Still having seperate copy of string "RajeevKumarNayan" which is ellogical.		



		const RCString str5("ThisIsConstString");
		str5.showStr();
		char ch1 = str5[3];		   //Non Const RCString Read.
		str5.showStr();			   //No address change after read, because of const


		RCString str6("ThisIsNonConstString");
		str6.showStr();
		char ch2 = str6[1];			//String changed while reading.
		str6.showStr();				//Address changed.

		*/
	}
	getchar();
	return 0;
}