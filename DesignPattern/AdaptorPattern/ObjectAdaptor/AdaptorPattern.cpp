#include <iostream>
#include <string>

using namespace std;

typedef int Cable; // wire with electrons :-)

/* Adaptee (source) interface */
class EuropeanSocketInterface
{
public:
	virtual int voltage() = 0;

	virtual Cable live() = 0;
	virtual Cable neutral() = 0;
	virtual Cable earth() = 0;
};

/* Adaptee */
class Socket : public EuropeanSocketInterface
{
public:
	int voltage() { return 230; }

	Cable live() { return 1; }
	Cable neutral() { return -1; }
	Cable earth() { return 0; }
};

/* Target interface */
class USASocketInterface
{
public:
	virtual int voltage() = 0;

	virtual Cable live() = 0;
	virtual Cable neutral() = 0;
};

/* The Adapter */
class Adapter : public USASocketInterface
{
	EuropeanSocketInterface* socket;

public:
	void plugIn(EuropeanSocketInterface* outlet)
	{
		socket = outlet;
	}

	int voltage() { return 110; }
	Cable live() { return socket->live(); }
	Cable neutral() { return socket->neutral(); }
};

/* Client */
class ElectricKettle
{
	USASocketInterface* power;

public:
	void plugIn(USASocketInterface* supply)
	{
		power = supply;
	}

	void boil()
	{
		if (power->voltage() > 110)
		{
			std::cout << "Kettle is on fire!" << std::endl;
			return;
		}

		if (power->live() == 1 && power->neutral() == -1)
		{
			std::cout << "Coffee time!" << std::endl;
		}
	}
};


int main()
{
	/*
	Old existing code. Socket(European style)
	support three cable- live, neutral and earth.
	suport constant voltage supply 220v.
	*/
	
	Socket* socket = new Socket;
	
	/*
	Electric Kettle is our clint.Its has below requirent-
		-It run on only 110v.
		-It dont required earthing cable.
		-This required US style Socket.

	Now, this is a problem, we cant plugin Electric Kettle into socket directly.
	due to high voltage & addition cabling.
	*/

	ElectricKettle* kettle = new ElectricKettle;

	/*
	Move to the soultion:
	
	Client need aceess the existing code, but inteface is not compatiable. 
	  -It doesnot required the earthing connection.
	  -Required the voltage only 110v.

    We need somthing which adject the voltage & disable/remove the earthing cable.
	Adpoter has a socket, but before plugin its resposibiliry to adjust the voltage in 
	remove the earthing cable.

	In nutshell we cant say that, this is provide the interface which makes our clint kettle 
	(new interface) compatible with socket(Old system/existing code ) 

	*/

	Adapter* adapter = new Adapter;	
		
	/* Pluging in Process :	First Adapter must be plugin into socket
		Now adapter provide only 110v & remove earthing cable, which is required by our clint.	
	*/

	adapter->plugIn(socket);

	/*
	Second, Our adptor is quite familier with Kettel, we can directly plugin kettle into it
	without any harzad.
	*/
	kettle->plugIn(adapter);

	
	/* And then, have a coffee */
	
	kettle->boil();

	getchar();

	return 0;
}