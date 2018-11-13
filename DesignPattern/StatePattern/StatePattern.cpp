#include<iostream>
#include "MusicPlayer.h"
using namespace std;




int main()
{
	MusicPlayer player;

	player.Play();
	player.Play();   //Illigal transition
	player.Pause();
	player.Stop();
	player.Pause();	 //Illigal transition

	getchar();
	return 0;
}