#include<iostream>

using namespace std;
/*
class TextBlock {
public:

	TextBlock(const string &str):text(str){}
	
	const char& operator[](std::size_t position) const
	{
		// do bounds checking
		// log access data
		// verify data integrity
		if(text.length() < position){
			cout<<"Invalid index ::"<<position<<endl;
			return text[text.length()-1];
		}
		else{
			cout<<"Index Validation successful\n";
		}
		
		
		return text[position];
	}
	
	char& operator[](std::size_t position)
	{
		//use const version of this method for preventing code duplication.
		return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
		
		
	}
	
	void display(){
		cout<<text.c_str()<<endl;
	}
private:
std::string text;
};

*/


class TextBlock {
public:

	TextBlock(const string &str):text(str){}
	
	
	
	char& operator[](std::size_t position)
	{
		
		
		// do bounds checking
		// log access data
		// verify data integrity
		if(text.length() < position){
			cout<<"Invalid index ::"<<position<<endl;
			return text[text.length()-1];
		}
		else{
			cout<<"Index Validation successful\n";
		}
		
		return text[position];

		
		
	}
	const char& operator[](std::size_t position) const
	{

		//use const version of this method for preventing code duplication.
		
		return const_cast<const TextBlock&>(*this)[position];
			
		
	}
	

	
	void display(){
		cout<<text.c_str()<<endl;
	}
private:
std::string text;
};




int main(){

	const TextBlock tb1("Rajeev");
	
	tb1[0]='r';
	
	//tb1.display();
	
	return 0;
}

