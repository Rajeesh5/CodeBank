/*
 * Book.h
 *
 *  Created on: Apr 25, 2017
 *      Author: Robert Larson
 */

#ifndef BOOK_H_
#define BOOK_H_

#include "BookComponent.h"

#include <string>

class Book : public BookComponent {
public:
	Book(std::string bookTitle, std::string author);
	virtual ~Book();

	virtual void DisplayInfo();

private:
	std::string m_title;
	std::string m_author;

};

#endif /* BOOK_H_ */
