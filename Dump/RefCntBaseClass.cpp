#include<iostream>

using namespace std;


class RCObject {
public:


	//Surely at least the creator of the new RCObject is referring to it, but Why it is zero???
	RCObject() :refCount(1), shareable(true) {}

	//That's because we're creating a new object representing a value, and new values
	//are always unshared and referenced only by their creator, so refCount=1;
	RCObject(const RCObject &rhs) :refCount(1), shareable(true) {}
	
	RCObject& operator =(const RCObject &rhs) { return *this; }
	virtual ~RCObject() {}

	void addRef() { ++refCount; }

	//removeReference is responsible not only for decrementing the object's refCount, but
	//also for destroying the object if the new value of refCount is 0.
	void removeRef() {
		if (--refCount == 0)			//Decrease refCnt and also delete if refCnt=0;
			delete this;
	}
	int getRefCnt() { return refCount; }				//Only for testing.	
	void markSharable() { shareable = true; }
	void markUnsharable() { shareable = false; }
	bool isShareable()const { return shareable; }
	bool isShared()const {
		return refCount > 1;
	}

private:
	short refCount;
	bool shareable;
};



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

int main() {


	{
		String str1("RajeevKumar");
		String str2(str1);
		String str3(str2);

		String str4("RajeevNayan");
		String str5(str4);


		//Before Assigmnet
		//(str1,str2,str3)->refCnt=2 value "RajeevKumar"
		//(str4,str5)     ->refCnt=1 value "RajeevNayan"

		str2 = str4;

		//After Assignment
		//(str1,str3)     ->refCnt=1 value "RajeevKumar"
		//(str2,str4,str4)->refCnt=2 value "RajeevNayan"


		str1.showStr();
		str2.showStr();
		str3.showStr();
		str4.showStr();
		str5.showStr();

		String str6("Mohan");
		String str7(str6);
		str6[0] = 'S';

		str6.showStr();
		str7.showStr();


	}

	
	




	getchar();
	return 0;
}