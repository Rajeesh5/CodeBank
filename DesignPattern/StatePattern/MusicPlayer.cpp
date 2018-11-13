#include "MusicPlayer.h"

#include "StoppedState.h"
#include "PlayingState.h"
#include "PausedState.h"


MusicPlayer::MusicPlayer()
	: m_pState(new StoppedState("Stoped")) {

}

MusicPlayer::~MusicPlayer() {
	delete m_pState;
}

void MusicPlayer::Play() {
	m_pState->Play(this);
}

void MusicPlayer::Pause() {
	m_pState->Pause(this);
}

void MusicPlayer::Stop() {
	m_pState->Stop(this);
}

void MusicPlayer::SetState(MusicPlayerState *state)
{
	std::cout << "changing from " << m_pState->GetName().c_str() << " to ";
	delete m_pState;

	m_pState = state;

	std::cout << m_pState->GetName().c_str() << " state\n";
}