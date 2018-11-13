

#include "StoppedState.h"
#include "PlayingState.h"


StoppedState::StoppedState(std::string nm) {
	name = nm;
}
StoppedState::~StoppedState() {}

void StoppedState::Play(MusicPlayer * player) {
		player->SetState(new PlayingState("Playing"));
	}

void StoppedState::Stop(MusicPlayer * player) {
	std::cout << "Illegal state transition from " << GetName().c_str() << " to stoped\n";
}

void StoppedState::Pause(MusicPlayer * player) {
	std::cout << "Illegal state transition from " << GetName().c_str() << " to Poused\n";
}

std::string StoppedState::GetName() {
	return name;
}
