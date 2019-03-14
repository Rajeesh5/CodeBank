#include<iostream>


template <class KEY, class VALUE>
class CMap
{
public:

	CMap(int HintMaxSize = 2048);
	~CMap(void);
	
	VALUE * Lookup(KEY const & Key);
	const VALUE * Lookup(KEY const & Key) const;
	VALUE & operator[](KEY const & Key);				//It works for set and get both.

	void SetAt(KEY const & Key, VALUE const & NewValue);
	
	bool RemoveKey(KEY const & Key);
	void RemoveAll(void);

	bool IsEmpty(void) const;
	unsigned GetCount() const { return m_nCount; } 
												   
protected:

	struct tagPair
	{
	public:
		tagPair(KEY const& Key)		: m_Key(Key), m_Value(VALUE())	{}
		tagPair(KEY const& Key, VALUE const& Value)	: m_Key(Key), m_Value(Value)	{}
		tagPair(tagPair const & ToCopyC) : m_Key(ToCopyC.m_Key), m_Value(ToCopyC.m_Value) {}

		//assigns a tagPair instance to another tagPair instance
		tagPair & operator=(tagPair const & ToAssign){
			if (this != &ToAssign){
				m_Key = ToAssign.m_Key;
				m_Value = ToAssign.m_Value;
			}
			return (*this);
		}


		bool operator==(tagPair const& Right) const{
			return (m_Key == Right.m_Key);
		}

		bool operator<(tagPair const& Right) const{
			return (m_Key < Right.m_Key);
		}				
		KEY   m_Key;	// cmember Attribute to store the key of an map entry.		
		VALUE m_Value;	// cmember Attribute to store the value of a map entry.
	}; // end of struct tagPair
	
	// @cmember Number of entries
	unsigned m_nCount;	

	//Disable copy ctor & assigmnet operator.
	CMap(const CMap&);
	CMap & opertor ==(const CMap&);

}; // end of class CFwMap< KEY, VALUE >