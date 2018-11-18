/*
 * BookComponent.h
 *
 *  Created on: Apr 25, 2017
 *      Author: Robert Larson
 */

#ifndef BOOKCOMPONENT_H_
#define BOOKCOMPONENT_H_


class BookComponent
{
public:
	BookComponent()
	{

	}
	virtual ~BookComponent()
	{

	}

	virtual void Add(BookComponent * newComponent)
	{

	}

	virtual void Remove(BookComponent * newComponent)
	{

	}

	virtual void DisplayInfo() = 0;
};



#endif /* BOOKCOMPONENT_H_ */
