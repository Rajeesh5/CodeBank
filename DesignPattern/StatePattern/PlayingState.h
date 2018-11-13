#pragma once

#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "MusicPlayerState.h"

class PlayingState : public MusicPlayerState {
public:
	PlayingState();
	virtual ~PlayingState();

	virtual void Pause(MusicPlayer * player);	
	virtual void Stop(MusicPlayer * player);
};

#endif // !PLAYINGSTATE_H