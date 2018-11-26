/*
 * RobotDogAdapter.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: Robert Larson
 */

#include "RobotDogAdapter.h"

#include "RobotDog.h"

RobotDogAdapter::RobotDogAdapter(RobotDog * robotDog)
: m_pRobotDog(robotDog)
{

}

RobotDogAdapter::~RobotDogAdapter() {

}

void RobotDogAdapter::Bark()
{
   m_pRobotDog->PlayBarkingSound();
}


