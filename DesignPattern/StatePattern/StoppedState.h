#pragma once

#ifndef STOPPEDSTATE_H_
#define STOPPEDSTATE_H_
#include "MusicPlayerState.h"

class StoppedState : public MusicPlayerState {
public:
	StoppedState(std::string nm);
	virtual ~StoppedState();
	
	virtual void Play(MusicPlayer * player);

	
	virtual void Stop(MusicPlayer * player);
	virtual void Pause(MusicPlayer * player);
	virtual std::string GetName();
	
};
#endif // !STOPPEDSTATE_H_