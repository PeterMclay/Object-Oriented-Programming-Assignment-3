#include <iostream>
#include "MatchCard.h"
#include "List.h"
#include "Queue.h"
#include "MatchPlayer.h"
#include "MatchGame.h"
#include "Stack.h"
using namespace std;
int main()
{
	cout << "Welcome to MATCH!" << endl;
	int num_players;
	int max_rank;
	cout << "How many players will be playing? "; cin >> num_players;
	cout << endl;
	while (num_players <= 1)	//validates there is more then one player
	{
		cout << "You need more then one player to play match." << endl;
		cout<<"Please enter how many players wil be playing: "; cin >> num_players;
		cout << endl;
	}
	cout << "Enter the MAX RANK of cards: "; cin >> max_rank;
	while ((max_rank * 4) <= (num_players * 6))	//validates that there is enough cards for each player
	{
		cout << "You need a larger MAX RANK to have enough cards for the players." << endl;
		cout << "Please enter a larger MAX RANK: "; cin >> max_rank;
		cout << endl;
	}
	MatchGame _play(num_players, max_rank);
	_play.play();
}