


template<class T>
class auto_ptr {
public:
	explicit auto_ptr(T *p = 0);
	template<class U>			// copy constructor member
	auto_ptr(auto_ptr<U>& rhs); // initialize a new auto_ptr
								// with any compatible auto_ptr
	~auto_ptr();

	template<class U>								// assignment operator
	auto_ptr<T>& operator=(auto_ptr<U>& rhs);		// member template assign from any
													// compatible auto_ptr
	T& operator*() const; 
	T* operator->() const; 
	T* get() const;				// return value of current dumb pointer
	T* release();				// relinquish ownership of current dumb pointer and
								// return its value
	void reset(T *p = 0);		// delete owned pointer; assume ownership of p
private:
	T *pointee;
	template<class U> // make all auto_ptr classes
	friend class auto_ptr<U>; // friends of one another
};

template<class T>
inline auto_ptr<T>::auto_ptr(T *p): pointee(p){}

template<class T>
inline auto_ptr<T>::auto_ptr(auto_ptr<U>& rhs): pointee(rhs.release()){}

template<class T>
inline auto_ptr<T>::~auto_ptr(){
	delete pointee;
}

template<class T>
template<class U>
inline auto_ptr<T>& auto_ptr<T>::operator=(auto_ptr<U>& rhs){
	if (this != &rhs) reset(rhs.release());
	return *this;
}

template<class T>
inline T& auto_ptr<T>::operator*() const{
	return *pointee;
}

template<class T>
inline T* auto_ptr<T>::operator->() const{
	return pointee;
}

template<class T>
inline T* auto_ptr<T>::get() const{
	return pointee;
}

template<class T>
inline T* auto_ptr<T>::release(){
	T *oldPointee = pointee;
	pointee = 0;
	return oldPointee;
}

template<class T>
inline void auto_ptr<T>::reset(T *p)
{
	if (pointee != p) {
		delete pointee;
		pointee = p;
	}
}

template<class T>
class auto_ptr {
public:
	explicit auto_ptr(T *p = 0) : pointee(p) {}
	template<class U>
	auto_ptr(auto_ptr<U>& rhs) : pointee(rhs.release()) {}
	~auto_ptr() { delete pointee; }
	
	template<class U>
	auto_ptr<T>& operator=(auto_ptr<U>& rhs){
		if (this != &rhs) reset(rhs.release());
		return *this;
	}
	
	T& operator*() const { return *pointee; }
	T* operator->() const { return pointee; }
	T* get() const { return pointee; }

	T* release(){
		T *oldPointee = pointee;
		pointee = 0;
		return oldPointee;
	}
	void reset(T *p = 0)
	{
		if (pointee != p) {
			delete pointee;
			pointee = p;
		}
	}
private:
	T *pointee;
	template<class U> friend class auto_ptr<U>;
};
