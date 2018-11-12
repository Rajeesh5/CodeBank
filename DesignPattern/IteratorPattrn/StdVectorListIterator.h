#pragma once

template <class Item>
class StdVectorListIterator : public Iterator<Item> {
public:
	StdVectorListIterator(const StdVectorList<Item> * list)
		: m_pList(list),
		m_index(0)
	{
	}

	virtual ~StdVectorListIterator(){	}

	virtual void First()	{
		m_index = 0;
	}

	virtual void Next()	{
		m_index++;
	}

	virtual bool IsDone() const	{
		return (m_pList->Count() <= m_index);
	}

	virtual Item CurrentItem() const{
		if (IsDone())
		{
			return Item();
		}
		return m_pList->Get(m_index);
	}

private:
	const StdVectorList<Item> * m_pList;

	unsigned int m_index;
};