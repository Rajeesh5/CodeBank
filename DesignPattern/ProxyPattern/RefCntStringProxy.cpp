#include<iostream>

using namespace std;


class RCObject {
public:

	RCObject():refCount(0),shareable(true){}
	RCObject(const RCObject &rhs):refCount(0), shareable(true) {}
	RCObject& operator =(const RCObject &rhs) { return *this; }
	virtual ~RCObject() {}

	void addRef() { ++refCount; }
	void removeRef() {
		if (--refCount == 0)
			delete this;
	}

	void markSharable() { shareable = true; }
	bool isShareable()const { return shareable; }
	bool isShared()const {
		return refCount > 1;
	}

private:
	short refCount;
	bool shareable;
};


struct StringValue:public RCObject {
	
public:
	StringValue(const char *initValue) {
		data = new char[strlen(initValue) + 1];
		strcpy(data, initValue);
	}
	~StringValue() {
		delete[] data;
	}
private:
	char *data;
};


class RCString 
{
private:

	StringValue *value; // value of this String

public:

	RCString(const char *initValue = "");
	RCString(const RCString& rhs);
	RCString& operator=(const RCString& rhs);
	char& operator[](int index)const;				//For Const String
	char& operator[](int index);					//For non-Const String.
	~RCString();
	void showStr()const {
		cout << "Data:: " << value->data << ", Ref cnt:: " << value->refCount << ", Address::" << &(value->data)<<endl;;
	}
};

