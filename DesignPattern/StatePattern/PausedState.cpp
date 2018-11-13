
#include "PausedState.h"
#include "PlayingState.h"
#include "StoppedState.h"
#include <string>



PausedState::PausedState() :MusicPlayerState(std::string("Paused")) {}
PausedState::~PausedState() {}

void PausedState::Play(MusicPlayer * player) {
		player->SetState(new PlayingState());
	}
void PausedState::Stop(MusicPlayer * player) {
		player->SetState(new StoppedState());
	}

