#pragma once
#ifndef PAUSEDSTATE_H_
#define PAUSEDSTATE_H_

#include "MusicPlayerState.h"

class PausedState : public MusicPlayerState {
public:
	PausedState(std::string nm);
	virtual ~PausedState();

	virtual void Play(MusicPlayer * player);
	virtual void Stop(MusicPlayer * player);

	virtual void Pause(MusicPlayer * player);
	virtual std::string GetName();
};

#endif // !PAUSEDSTATE_H_