/*
 * Book.cpp
 *
 *  Created on: Apr 25, 2017
 *      Author: Robert Larson
 */

#include "Book.h"

#include <iostream>

Book::Book(std::string title, std::string author)
: m_title(title),
  m_author(author)
{
}

Book::~Book()
{
}

void Book::DisplayInfo()
{
	std::cout << "Book  : " << m_title << " by " << m_author << "\n";
}
