/*
 * RobotDog.h
 *
 *  Created on: Apr 3, 2017
 *      Author: Robert Larson
 */

#ifndef ROBOTDOG_H_
#define ROBOTDOG_H_

#include <string>

class RobotDog {
public:
	RobotDog(std::string name);
	virtual ~RobotDog();

	void PlayBarkingSound();
private:
	std::string m_name;
};

#endif /* ROBOTDOG_H_ */
