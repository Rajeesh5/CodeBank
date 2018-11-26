#include "CellPhoneTextApp.h"

class CellPhoneTextAppImpl;

class GalaxyS8TextApp : public CellPhoneTextApp {
public:
	GalaxyS8TextApp(CellPhoneTextAppImpl * impl) : CellPhoneTextApp(impl) { }
	virtual ~GalaxyS8TextApp(){}

	virtual void Open() {
		std::cout << "Opening Galaxy S8 Text App.\n\n";
	}
	virtual void Close() {
		std::cout << "Closing Galaxy S8 Text App.\n\n";
	}
};