#include<iostream>
#include "MusicPlayer.h"
using namespace std;




int main()
{
	MusicPlayer player;

	player.Play();
	player.Play();
	player.Pause();
	player.Stop();

	getchar();
	return 0;
}