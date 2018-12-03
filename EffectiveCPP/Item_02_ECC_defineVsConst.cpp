#include<iostream>

using namespace std;



class GamePlayer {
public:
	static const int NumTurns = 5; // constant declaration
	int scores[NumTurns]; // use of constant

};


int main_01() {
	//We can use it even without declearing it.
	cout << GamePlayer::NumTurns << endl;

	getchar();
	return 0;
}