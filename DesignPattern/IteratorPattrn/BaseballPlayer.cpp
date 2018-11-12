#include"BaseballPlayer.h"

BaseballPlayer::BaseballPlayer
(std::string name,
	std::string position,
	char swingType)
	: m_name(name),
	m_position(position),
	m_swingType(swingType) {

}
BaseballPlayer::BaseballPlayer()
	: m_swingType('\0') {

}
BaseballPlayer::~BaseballPlayer() {
}

std::ostream& operator<<(std::ostream& outc,
	const BaseballPlayer & player)
{
	std::string tabsAfterName =
		(player.GetName().size() >= 16) ?
		std::string("\t") : std::string("\t\t");;
	outc << player.GetPosition().c_str() << "\t"
		<< player.GetName().c_str() << tabsAfterName.c_str()
		<< player.GetSwingType();

	return outc;
}