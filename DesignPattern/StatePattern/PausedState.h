#pragma once
#ifndef PAUSEDSTATE_H_
#define PAUSEDSTATE_H_

#include "MusicPlayerState.h"

class PausedState : public MusicPlayerState {
public:
	PausedState();
	virtual ~PausedState();

	virtual void Play(MusicPlayer * player);
	virtual void Stop(MusicPlayer * player);
};

#endif // !PAUSEDSTATE_H_