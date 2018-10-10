#pragma once
#include <string>
#include "MatchCard.h"
#include "OrderedList.h"
#include "Queue.h"
#include "Functors.h"
#include <iostream>
using namespace std;
class MatchPlayer {
private:
	int pNumber; // Used for turn order. 
	string pName = "Player "; // the name of the computer player
	OrderedList<MatchCard> pHand; // their hand of cards
	friend std::ostream& operator<<(std::ostream& out, const MatchPlayer&c); // prints players name
public:

	MatchPlayer(); //Constructor
	~MatchPlayer();
	int matchFindRank(MatchCard upCard); // returns index in the list of card with rank = to rank of faceup pile
	int matchFindSuit(MatchCard upCard);	//return index in the list of card with suit = to suit of faceup pile
	inline int getNumber(void) const {	//returns players number
		return pNumber;
	}
	inline int getHandSize(void)const { //returns size of hand
		return pHand.getLength();
	}
	void setNumber(int num) {	//sets number used for players name 
		pNumber = num +1;
	}
	void draw(MatchCard card); //Grabs 6 cards from queue
	MatchCard showHand(int num);	//prints hand
	MatchCard discardCard(int index);	//puts matching card into stack
										
};
