#include<iostream>

using namespace std;


class Dog	//Target
{
public:
	virtual ~Dog() {}
	virtual void Bark() = 0;
};


class RobotDog {   //Adaptee
public:
	RobotDog():m_name("nil"){}
	RobotDog(std::string name) :m_name(name) {}
	virtual ~RobotDog(){}

	void PlayBarkingSound() {
		std::cout << m_name.c_str() << " is playing barking sound\n";
	}
private:
	std::string m_name;
};


class RobotDogAdapter : public Dog,public RobotDog {	//Adaptor.
public:
	RobotDogAdapter(RobotDog * robotDog) : m_pRobotDog(robotDog) {}
	virtual ~RobotDogAdapter(){}

	virtual void Bark() {
		m_pRobotDog->PlayBarkingSound();
	}

private:
	RobotDog * m_pRobotDog;
};



int main() {
	
	RobotDog * robotDog = new RobotDog(std::string("Sony's Aibo"));
	Dog * robotDogAdapter = new RobotDogAdapter(robotDog);
	robotDogAdapter->Bark();


	delete robotDogAdapter;
	delete robotDog;


	getchar();
	return 0;
}

