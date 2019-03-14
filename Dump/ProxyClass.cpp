#include<iostream>

using namespace std;


template<class T>
class Array2D {

private:

	T **arr;
	int r, c;
public:
	Array2D(int row, int col):r(row),c(col) {
		arr = new T * [r];
		for (int i = 0;i < c;i++)
			arr[i] = new T[c];

	}

	~Array2D() {

		for (int i = r - 1;i >= 0;i--)
		{
			cout << "deleting mem loc::" << arr[i] << endl;
			delete[]  arr[i];
		}
		cout << "finally deleted arr::" << arr << endl;
		delete  []arr;
	}

	void setElement() {
		for (int i = 0;i < r;i++)
			for (int j = 0;j < c;j++)
				arr[i][j] = i + j;
	}

	void showElement() {
		for (int i = 0;i < r;i++)
		{
			for (int j = 0;j < c;j++)
				cout << arr[i][j];
			cout << "\n";
		}
	}

	//Proxy Class..
	class Array1D {		
	private:
		T *oneDArray;
	public:
		Array1D(T *mVar):oneDArray(mVar){}
		
		T& operator[](int index) { 
			return 	oneDArray[index];
		}
		
		const T& operator[](int index) const{}
		
	};

	Array1D operator[](int index) {
		return Array1D(arr[index]);
	}
	const Array1D operator[](int index) const {}
	
};

/*

=>Each Array1D object stands for a one - dimensional array that is absent from the conceptual model used by clients of Array2D.

=>Objects that stand for other objects are often called proxy objects, and the classes that give rise to
  proxy objects are often called proxy classes.

=>In this example, Array1D is a proxy class.Its instances stand for one - dimensional arrays that, conceptually, do not exist. 
  The terminology for proxy objects and classes is far from universal; objects of such classes are also sometimes known as surrogates.

*/

int main() {

	
		Array2D<int> a1(10, 10);
		a1.setElement();
		a1.showElement();
	

	cout << a1[9][9];

	getchar();
	return 0;
}


