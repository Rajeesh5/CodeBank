
#include "PlayingState.h"
#include <string>
#include "PausedState.h"
#include "StoppedState.h"

PlayingState::PlayingState() :MusicPlayerState(std::string("Playing")) {}

PlayingState::~PlayingState() {}
void PlayingState::Pause(MusicPlayer * player) {
		player->SetState(new PausedState());
	}

void PlayingState::Stop(MusicPlayer * player) {
		player->SetState(new StoppedState());
	}
