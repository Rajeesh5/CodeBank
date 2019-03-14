#include<iostream>

using namespace std;

template <class T>
class  RCPtr
{
public:
	RCPtr(T* realPtr = 0) :pointee(realPtr) {
		init();
	}
	RCPtr(const RCPtr &rhs) :pointee(rhs.pointee) {
		init();
	}
	~RCPtr() {
		if (pointee)
			pointee->removeRef();
	}
	RCPtr& operator =(const RCPtr &rhs) {
		if (pointee != rhs.pointee) {	//skip assignments where values dosenot change
			if (pointee) {
				pointee->removeRef();	//Remove ref to current value
			}
			pointee = rhs.pointee;		//point to the new value if possible, share it
			init();						//else make own copy.
		}
		return *this;
	}

	T* operator->()const {
		return pointee;
	}
	T& operator*() const {
		return *pointee;
	}

private:
	T *pointee;
	void init() {
		if (pointee == 0) {		//if the dumb pointer is null, so it is smart one.
			return;
		}
		if (pointee->isShareable() == false) {  //If the value is not sharable copy it.
			pointee = new T(*pointee);
		}
		pointee->addRef();	//note that there is now a new reference to the value.
	}
};

class RCObject {
public:

	RCObject() :refCount(0), shareable(true) {}
	RCObject(const RCObject &rhs) :refCount(0), shareable(true) {}
	RCObject& operator =(const RCObject &rhs) { return *this; }
	virtual ~RCObject() {}

	void addRef() { ++refCount; }
	void removeRef() {
		if (--refCount == 0)
			delete this;
	}

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

struct StringValue :public RCObject {

public:
	void init(const char * initValue) {
		data = new char[strlen(initValue) + 1];
		strcpy(data, initValue);
	}
	StringValue(const char *initValue) {
		data = new char[strlen(initValue) + 1];
		strcpy(data, initValue);
	}
	StringValue(const StringValue& rhs) {
		data = new char[strlen(rhs.data) + 1];
		strcpy(data, rhs.data);
	}
	~StringValue() {
		delete[] data;
	}
private:
public:
	char *data;
};

class String
{
private:

	RCPtr<StringValue> value; // value of this String

public:

	String(const char *initValue = "") :value(new StringValue(initValue)) {}
	String(const String& rhs);
	~String();


	String& operator=(const String& rhs);

	const char& operator[](int index)const {				//For Const String
		return value->data[index];
	}
	char& operator[](int index) {						//For non-Const String.
		if (value->isShared()) {
			value = new StringValue(value->data);
		}
		value->markUnsharable();
		return value->data[index];
	}

	/*
	void showStr()const {
	cout << "Data:: " << value.data << ", Ref cnt:: " << value->refCount << ", Address::" << &(value->data) << endl;;
	}*/
};

int main() {
	StringValue sv1("Rajeev"), sv2("Sharma");

	StringValue *str = new StringValue(sv1);

	getchar();
}