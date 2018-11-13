

#include "StoppedState.h"
#include "PlayingState.h"
#include <string>


StoppedState::StoppedState() :MusicPlayerState(std::string("Stoped")) {}
StoppedState::~StoppedState() {}

void StoppedState::Play(MusicPlayer * player) {
		player->SetState(new PlayingState());
	}
