#pragma once
#ifndef MUSICPLAYER_H_
#define MUSICPLAYER_H_

class MusicPlayerState;

class MusicPlayer {
public:

	MusicPlayer();
	virtual ~MusicPlayer();

	void Play();
	void Pause();
	void Stop();

	void SetState(MusicPlayerState *state);
		
	
private:
	MusicPlayerState * m_pState;
};

#endif /* MUSICPLAYER_H_ */