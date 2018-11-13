
#include "PausedState.h"
#include "PlayingState.h"
#include "StoppedState.h"




PausedState::PausedState(std::string nm) {
	name = nm;
}
PausedState::~PausedState() {}

void PausedState::Play(MusicPlayer * player) {
		player->SetState(new PlayingState("Playing"));
	}
void PausedState::Stop(MusicPlayer * player) {
		player->SetState(new StoppedState("Stoped"));
	}

void PausedState::Pause(MusicPlayer * player) {
	std::cout << "Illegal state transition from " << GetName().c_str() << " to Poused\n";
}

std::string PausedState::GetName() {
	return name;
}
