#include<iostream>


using namespace std;



class TextBlockString {
public:
	TextBlockString(const string &ref):text(ref){}

	const char& operator[](std::size_t position) const // operator[] for
	{
		return text[position];
	} // const objects

	
	char& operator[](std::size_t position) // operator[] for
	{
		return text[position];
	} // non-const objects
	
private:
	std::string text;
};


class TextBlockChar {

public:
	TextBlockChar(const char *ref) {
		m_pStr = new char[strlen(ref) + 1];
		strcpy(m_pStr, ref);

	}
	char& operator[](std::size_t position) const // operator[] for
	{
		return m_pStr[position];
	} // const objects
	char& operator[](std::size_t position) // operator[] for
	{
		return m_pStr[position];
	} // non-const objects

private:
	char *m_pStr;
};

int main_1() {

	TextBlockString tb1("Rajeev");
	tb1[3] = 'R';


	const TextBlockString tb2("Rajeev");

	//char *ch = &tb2[0];
	
	return 0;

}