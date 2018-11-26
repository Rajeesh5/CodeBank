#include "CellPhoneTextApp.h"

class IPhone8TextApp : public CellPhoneTextApp {
public:
	IPhone8TextApp(CellPhoneTextAppImpl * impl) : CellPhoneTextApp(impl) {}
	virtual ~IPhone8TextApp(){}

	virtual void Open() {
		std::cout << "Opening IPhone 8 Text App.\n\n";
	}
	virtual void Close() {
		std::cout << "Closing IPhone 8 Text App.\n\n";
	}
};