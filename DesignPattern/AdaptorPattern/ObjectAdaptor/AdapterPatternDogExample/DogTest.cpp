/*
 * DogTest.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: Robert Larson
 */

#include "LivingDog.h"
#include "RobotDog.h"
#include "RobotDogAdapter.h"

int main()
{
    Dog * livingDog = new LivingDog(std::string("Chester"));
    livingDog->Bark();

    RobotDog * robotDog = new RobotDog(std::string("Sony's Aibo"));
    Dog * robotDogAdapter = new RobotDogAdapter(robotDog);
    robotDogAdapter->Bark();

    delete livingDog;
    delete robotDogAdapter;
    delete robotDog;

	return 0;
}


