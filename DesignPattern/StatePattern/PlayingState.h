#pragma once

#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "MusicPlayerState.h"

class PlayingState : public MusicPlayerState {
public:
	PlayingState(std::string nm);
	virtual ~PlayingState();

	virtual void Pause(MusicPlayer * player);	
	virtual void Stop(MusicPlayer * player);
	virtual void Play(MusicPlayer * player);
	virtual std::string GetName();
};

#endif // !PLAYINGSTATE_H