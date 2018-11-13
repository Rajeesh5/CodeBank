
#include "MusicPlayerState.h"
#include <iostream>


MusicPlayerState::MusicPlayerState(std::string name) :
	m_name(name) {}

MusicPlayerState::~MusicPlayerState() {}

void MusicPlayerState::Play(MusicPlayer * player) {
		std::cout << "Illegal state transition from " << GetName().c_str() << " to Playing\n";
}
void MusicPlayerState::Pause(MusicPlayer * player) {
		std::cout << "Illegal state transition from " << GetName().c_str() << " to Poused\n";
	}
void MusicPlayerState::Stop(MusicPlayer * player) {
		std::cout << "Illegal state transition from " << GetName().c_str() << " to stoped\n";
	}

std::string MusicPlayerState::GetName() { return m_name; }


