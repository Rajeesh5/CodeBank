/*
 * Librarian.cpp
 *
 *  Created on: Apr 25, 2017
 *      Author: Robert Larson
 */

#include "Librarian.h"

#include "BookComponent.h"

#include "BookGroup.h"
#include "Book.h"

Librarian::Librarian()
: m_pBookCollection(new BookGroup(std::string("Book Collection")))
{
	BuildBookCollection();
}

Librarian::~Librarian() {
	delete m_pBookCollection;
}

void Librarian::BuildBookCollection()
{
	/*
	AddBookToGroup(m_pBookCollection,
				   std::string("Operating system"),
			       std::string("DhamDhre.."));

	m_pBookCollection->Add(BuildFictionGroup());
	m_pBookCollection->Add(BuildNonfictionGroup());
	*/

	BookComponent * tech = new BookGroup(std::string("Technical Books"));
	BookComponent * cs = new BookGroup(std::string("Computer Science"));
	BookComponent * ecs = new BookGroup(std::string("Electronics & Computer Science"));
	
		
	BookComponent * nTech = new BookGroup(std::string("Non-Technical Books"));
	BookComponent * literature = new BookGroup(std::string("Literature"));
	BookComponent * hindi = new BookGroup(std::string("HindiBooks"));
	BookComponent * hStory = new BookGroup(std::string("Hindi Story Books"));
	BookComponent * hPoem = new BookGroup(std::string("Hindi Poem Books"));

	BookComponent * english = new BookGroup(std::string("EnglishBooks"));
	BookComponent * eStory = new BookGroup(std::string("English Story Books"));
	BookComponent * ePoem = new BookGroup(std::string("English Poem Books"));

	BookComponent * bio = new BookGroup(std::string("Biography"));


	m_pBookCollection->Add(tech);

	tech->Add(cs);
	AddBookToGroup(cs, std::string("Operating system"), std::string("Mr. DhamDhre"));
	AddBookToGroup(cs, std::string("Automata theory "), std::string("Linz."));
	AddBookToGroup(cs, std::string("Algorithm"), std::string("Mr. Corman"));

	tech->Add(ecs);
	AddBookToGroup(ecs, std::string("Circuit Theory"), std::string("Known."));
	AddBookToGroup(ecs, std::string("Discrete Math" ), std::string("Known."));

	

	m_pBookCollection->Add(nTech);
	nTech->Add(literature);
	literature->Add(hindi);
	hindi->Add(hStory);

	AddBookToGroup(hStory, std::string("Karmbhumi"), std::string("M. Premchandra"));
	
	hindi->Add(hPoem);

	AddBookToGroup(hPoem, std::string("Madhushala"), std::string("HR. Bachchan"));
	AddBookToGroup(hPoem, std::string("Urvashi"), std::string("RS. Dinker"));
	AddBookToGroup(hPoem, std::string("Kurukchetra"), std::string("RS. Dinker"));

	literature->Add(english);


	nTech->Add(bio);
	AddBookToGroup(bio, std::string("Wings of fire"), std::string("APJ. Kalam"));
	AddBookToGroup(bio, std::string("The Story Of My Experiments With Truth"), 
					std::string("Gandhi"));

}


/*
BookComponent * Librarian::BuildFictionGroup()
{
	BookComponent * fictionGroup = new BookGroup(std::string("Fiction"));

	fictionGroup->Add(BuildKidsGroup());

    return fictionGroup;
}

BookComponent * Librarian::BuildNonfictionGroup()
{
	BookComponent * nonfictionGroup = new BookGroup(std::string("Nonfiction"));

	nonfictionGroup->Add(BuildBiographyGroup());

    return nonfictionGroup;
}

BookComponent * Librarian::BuildKidsGroup()
{
	BookComponent * kidsGroup =
		new BookGroup(std::string("Kids"));

	AddBookToGroup(kidsGroup,
			       std::string("Harry Potter"),
				   std::string("Dr. Rajeev"));

	kidsGroup->Add(BuildKidsAges3To5Group());

    return kidsGroup;
}

BookComponent * Librarian::BuildKidsAges3To5Group()
{
	BookComponent * kidsAges3To5Group =
		new BookGroup(std::string("Kids (Ages 3-5)"));

	AddBookToGroup(kidsAges3To5Group,
			       std::string("Goodnight Moon"),
				   std::string("Vikas"));

    return kidsAges3To5Group;
}

BookComponent * Librarian::BuildBiographyGroup()
{
	BookComponent * biographyGroup = new BookGroup(std::string("Biography"));

	AddBookToGroup(biographyGroup,
			       std::string("Steve Jobs"),
			       std::string("Walter Isaacson"));

    return biographyGroup;
}
*/


void Librarian::AddBookToGroup(BookComponent * group,
		std::string bookTitle, std::string author)
{
	BookComponent * book = new Book(bookTitle, author);
    group->Add(book);
}

void Librarian::DisplayBookCollection()
{
	m_pBookCollection->DisplayInfo();
}
