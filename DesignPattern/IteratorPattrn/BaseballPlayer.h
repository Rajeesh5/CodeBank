#pragma once
#include<iostream>

class BaseballPlayer {
public:
	BaseballPlayer(std::string name,
		std::string position,
		char swingType);
	BaseballPlayer();
	virtual ~BaseballPlayer();

	std::string GetName()      const { return m_name; }
	std::string GetPosition()  const { return m_position; }
	char GetSwingType()        const { return m_swingType; }

private:
	std::string m_name;
	std::string m_position;
	char        m_swingType;
};