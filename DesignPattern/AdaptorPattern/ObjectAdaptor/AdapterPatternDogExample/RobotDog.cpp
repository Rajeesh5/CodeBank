/*
 * RobotDog.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: Robert Larson
 */

#include "RobotDog.h"

#include <iostream>

RobotDog::RobotDog(std::string name)
: m_name(name) {

}

RobotDog::~RobotDog() {
}

void RobotDog::PlayBarkingSound()
{
	std::cout << m_name << " is playing barking sound\n";
}
