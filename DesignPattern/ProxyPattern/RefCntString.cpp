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
	//char& operator[](int index)const;				//For Const String
	char& operator[](int index);					//For non-Const String.


	~RCString();
	void showStr()const {
		cout <<"Data:: "<<value->data<<endl;
		cout << "Ref cnt:: " << value->refCount<<endl;
		cout << "---------------\n";
	}
};

/*
char& RCString::operator[](int index)const
{
	if ((strlen(value->data) - 1) > index)
		return value->data[index];
	///else throw ArrayOutOfBoundExeception
}
*/

char& RCString::operator[](int index) //throw ArrayOutOfBoundExeception,Implement leter..
{
	if (value->refCount > 1)  //if shareable..
	{
		value->refCount--;
		value = new StringValue(value->data);
	}

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

RCString::RCString(const char *initValue): value(new StringValue(initValue))
{
}

RCString::RCString(const RCString& rhs):value(rhs.value) {

	++value->refCount;
}

RCString::StringValue::StringValue(const char *initValue):refCount(1) {
	data = new char[strlen(initValue) + 1];
	strcpy(data, initValue);
}

RCString::StringValue::~StringValue(){
	delete[] data;
}



int main() {

	{

		/*
		RCString s1("RefCntString");
		s1.showStr();

		RCString s2 = s1;	//Copy Constructor
		s2.showStr();

		RCString s3 = s1;	//Copy Constructor
		s3.showStr();
		
		RCString s4("MoreEffectiveC++");
		s4.showStr();


		s4 = s4;			//should take care of this case.
		s4 = s1;			//Assignment Operator overload.

		s4.showStr();

		const RCString s5("ThisIsConstString");


		char ch1 = s4[3];			//Non Const RCString Read
		char ch2 = s5[8];			//    Const RCString Read

		*/

		/*
		Problem with Write operation-When we modify a String's value, we have to be careful to avoid 
		modifying the value of other String objects.Because we all share same value among classes.
		And Unfortunately, there is no way for C++ compilers to tell us whether a particular use of 
		operator[] is for a read or a write.
		*/


		/*
		RCString str1("RajeevKumarSharma");
		RCString str2(str1);
		RCString str3(str2);

		
		
		//str2[0] = 'X';			//Now we will modifying str2, but It should not be inmpact str1

		//str1.showStr();			//RajeevKumarSharma,Ref cnt 1
		//str2.showStr();			//XajeevKumarSharma,Ref cnt 1
		

		char ch = str1[3];
		str1.showStr();
		str2.showStr();
		str3.showStr();

		str1 = "kjhsakh";
		str1.showStr();

		*/

		RCString s1("Rajeev");
		RCString s2("Rajeev");

		s1.showStr();
		s2.showStr();



	}
	getchar();
}


