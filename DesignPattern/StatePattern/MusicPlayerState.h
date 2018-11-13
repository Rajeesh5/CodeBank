#pragma once

#ifndef MUSICPLAYERSTATE_H_
#define MUSICPLAYERSTATE_H_

#include "MusicPlayer.h"
#include <iostream>

class MusicPlayerState {
public:
	virtual void Play(MusicPlayer * player) = 0;
	virtual void Pause(MusicPlayer * player) = 0;
	virtual void Stop(MusicPlayer * player) = 0;
	virtual std::string GetName() = 0;
protected:
	std::string name;
};

#endif 