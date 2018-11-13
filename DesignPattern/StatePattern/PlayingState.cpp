
#include "PlayingState.h"
#include "PausedState.h"
#include "StoppedState.h"

PlayingState::PlayingState(std::string nm) {
	name = nm;
}


PlayingState::~PlayingState() {}

void PlayingState::Pause(MusicPlayer * player) {
		player->SetState(new PausedState("Paused"));
	}

void PlayingState::Stop(MusicPlayer * player) {
		player->SetState(new StoppedState("Stoped"));
	}

void PlayingState::Play(MusicPlayer * player) {
	std::cout << "Illegal state transition from " << GetName().c_str() << " to Playing\n";
}

std::string PlayingState::GetName() {
	return name;
}