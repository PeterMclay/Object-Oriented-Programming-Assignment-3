#pragma once
#include <iostream>
#include "MatchCard.h"
#include "List.h"
#include "Queue.h"
#include "MatchPlayer.h"
#include "Stack.h"
using namespace std;
class MatchGame
{
private:
	MatchCard *_array;
	int NumPlayers;	//number of players
	int MaxRank;	//max rank of cards
	MatchCard *tmp;	//temp array of match cards
	Queue<MatchCard> Deck_Pile;	//Deck Pile queue of matchcards
	MatchPlayer *Player;	//Player array (container
	Stack<MatchCard> Face_up_pile; //Face up pile stack of matchcards
	MatchCard Face_Up_Card;	//face up card of face up pile
public:
	MatchGame(int num_players, int max_rank); //Creates all cards and places into an array
	~MatchGame();
	void play();	//Plays game
};


