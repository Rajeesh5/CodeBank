#include "SprintPhoneTextAppImpl.h"
#include "GalaxyS8TextApp.h"

#include "VerizonPhoneTextAppImpl.h"
#include "IPhone8TextApp.h"

void SendText(CellPhoneTextApp * textApp)
{
	textApp->Open();
		   
	textApp->AddRecipient(std::string("555-123-4567"));
	textApp->AddRecipient(std::string("555-765-4321"));
		   
	textApp->AddText(std::string("Can you hear me now?"));
		   
	textApp->SendText();
		   
	textApp->Close();
}


int main()
{
	
	SprintPhoneTextAppImpl sprintTextAppImpl;
	
	GalaxyS8TextApp        galaxyS8TextApp(&sprintTextAppImpl);
	
	
	SendText(&galaxyS8TextApp);
	
	
	VerizonPhoneTextAppImpl verizonTextAppImpl;

	
	IPhone8TextApp        iPhone8TextApp(&verizonTextAppImpl);

	SendText(&iPhone8TextApp);
	
	
	getchar();
	return 0;
}