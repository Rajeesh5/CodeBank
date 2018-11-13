#pragma once

#ifndef MUSICPLAYERSTATE_H_
#define MUSICPLAYERSTATE_H_

#include "MusicPlayer.h"
#include <string>

class MusicPlayerState {
public:
	MusicPlayerState(std::string name);
	virtual ~MusicPlayerState();

	virtual void Play(MusicPlayer * player);
	virtual void Pause(MusicPlayer * player);
	virtual void Stop(MusicPlayer * player);

	std::string GetName();

private:
	std::string   m_name;
};

#endif 