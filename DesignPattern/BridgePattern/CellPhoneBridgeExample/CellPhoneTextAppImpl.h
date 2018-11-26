#ifndef CELL_PHONE_TEXT_APP_IMPL__

#define CELL_PHONE_TEXT_APP_IMPL__
#include <string>
#include <vector>
#include <iostream>

class CellPhoneTextAppImpl
{
public:
	virtual void SendTextImpl(std::vector<std::string> recipients,
		std::string textField) = 0;

};
#endif // !CELL_PHONE_TEXT_APP_IMPL__


