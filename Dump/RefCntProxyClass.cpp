#include<iostream>

using namespace std;


class RCObject {
public:	
	RCObject() :refCount(1) {}
	RCObject(const RCObject &rhs) :refCount(1) {}	
	RCObject& operator =(const RCObject &rhs) { return *this; }
	virtual ~RCObject() {}
	void addRef() { ++refCount; }

	void removeRef() {
		if (--refCount == 0)			
			delete this;
	}
	int getRefCnt() { return refCount; }				//Only for testing.	
	bool isShared()const {
		return refCount > 1;
	}
private:
	short refCount;
};


/*
class String
{
private:
	struct StringValue :public RCObject {
		StringValue(const char * initValue) {
			int size = strlen(initValue);
			data = new char[size + 1];
			memset(data, 0, size + 1);
			memcpy(data, initValue,size);
		}
		~StringValue() {
			delete[] data;
		}
		char *data;
	};
	
	StringValue *value;											// value of this String

public:

	String(const char *initValue = "") :value( new StringValue(initValue)) {}
	
	String(const String& rhs):value(rhs.value) {
		value->addRef();
	}

	~String() {
		value->removeRef();					//Decrement the ref cnt. If ref cnt zero then only delete the string value(data).											
	}


	String& operator=(const String& rhs) {
		if (value == rhs.value)
			return *this;
		
		value->removeRef();					//Remove lhs refCnt, and also delete the data if refCnt=0;
		value = rhs.value;					//Assign value to the lhs
		value->addRef();					//Add ref cnt of lhs.
		return *this;
	}

	const char& operator[](int index)const {				//For Const String
		return value->data[index];
	}
	char& operator[](int index) {							//For non-Const String.
		if (value->isShared()) {
			value->removeRef();								//decrease the ref cnt.
			value = new StringValue(value->data);
		}
		value->markUnsharable();
		return value->data[index];
	}
	void showStr()const {
		cout << "Data:: " << value->data << ", Ref cnt:: " << value->getRefCnt() << ", Address::" << &(value->data) << endl;;
	}
};
*/



class String {				// Reference-counted strings Class
public:
	class CharProxy {		// Proxies for string chars
	public:
		CharProxy(String& str, int index); 				// creation

		CharProxy& operator=(const CharProxy& rhs); 	// lvalue uses
		CharProxy& operator=(char c); 					//	,,

		operator char() const; 							// rvalue uses
	private:
		String & theString; 			// string this proxy pertains 
										// to char within that string
		int charIndex; 					// this proxy stands for

	};
	
	const CharProxy operator[](int index) const;	//for const Strings
	CharProxy operator[](int index); 				//for non-const Strings
	//friend class CharProxy;

	struct StringValue :public RCObject {
		StringValue(const char * initValue) {
			int size = strlen(initValue);
			data = new char[size + 1];
			memset(data, 0, size + 1);
			memcpy(data, initValue, size);
		}
		~StringValue() {
			delete[] data;
		}
		char *data;
	};


	String(const char *initValue = "") :value(new StringValue(initValue)) {}
	String(const String& rhs) :value(rhs.value) {
		value->addRef();			//Point to same mem loc, increase ref cnt
	}
	~String() {
		value->removeRef();		//Decrement the ref cnt. If ref cnt zero, 
	}
	String& operator=(const String& rhs) {
		if (value == rhs.value)
			return *this;

		value->removeRef();		//Decrement lhs refCnt and delete the 
								//data if refCnt=0 by calling removeRef()
		value = rhs.value;		//Assign value to the lhs.
		value->addRef();			//Add ref cnt of lhs.
		return *this;
	}

private:
	StringValue *value;								// value of this String

};


String::CharProxy&
String::CharProxy::operator=(const CharProxy& rhs)
{
	// if the string is sharing a value with other String objects,
	// break off a separate copy of the value for this string only
	if (theString.value->isShared()) {
		theString.value->removeRef();
		theString.value = new StringValue(theString.value->data);
	}
	// now make the assignment: assign the value of the char
	// represented by rhs to the char represented by *this
	theString.value->data[charIndex] =
		rhs.theString.value->data[rhs.charIndex];
	return *this;
}

String::CharProxy& String::CharProxy::operator=(char c)
{
	if (theString.value->isShared()) {
		theString.value->removeRef();
		theString.value = new StringValue(theString.value->data);
	}
	theString.value->data[charIndex] = c;
	return *this;
}

const String::CharProxy String::operator[](int index) const
{
	return CharProxy(const_cast<String&>(*this), index);
}
String::CharProxy String::operator[](int index)
{
	return CharProxy(*this, index);
}

String::CharProxy::CharProxy(String& str, int index)
	: theString(str), charIndex(index) {}

String::CharProxy::operator char() const
{
	return theString.value->data[charIndex];
}


int main() {

	
	const String str1 = "Rajeev";
	
	
	



	getchar();
	return 0;
}