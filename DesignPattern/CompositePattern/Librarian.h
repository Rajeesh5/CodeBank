/*
 * Librarian.h
 *
 *  Created on: Apr 25, 2017
 *      Author: Robert Larson
 */

#ifndef LIBRARIAN_H_
#define LIBRARIAN_H_

#include <string>

class BookComponent;

class Librarian {
public:
	Librarian();
	virtual ~Librarian();

	void DisplayBookCollection();

private:
    void BuildBookCollection();
	/*
    BookComponent * BuildFictionGroup();
    BookComponent * BuildNonfictionGroup();

    BookComponent * BuildKidsGroup();
    BookComponent * BuildKidsAges3To5Group();
    BookComponent * BuildBiographyGroup();
	*/
    void AddBookToGroup(BookComponent * group,
    		            std::string bookTitle,
    		            std::string author);

    BookComponent * m_pBookCollection;
};

#endif /* LIBRARIAN_H_ */
