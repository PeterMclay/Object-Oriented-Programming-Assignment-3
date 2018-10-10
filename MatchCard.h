#pragma once
#include <iostream>

// User defined Suit and Denomination types (user-defined integers) 
enum Suit { SPADES = 1, HEARTS = 2, CLUBS = 3, DIAMONDS = 4 };
class MatchCard
{
public:
	MatchCard();
	MatchCard(Suit suit, int maxRank); // constructor with some default values
	~MatchCard(); // destructor
	inline Suit getSuit(void) const { return m_suit; }	//gets suit value
	char toCharSuit(void); // returns a char that "describes" card's suit
	inline int getrank(void) { return _Rank; }	//gets rank of card
	bool operator<(const MatchCard &compare) const;	//used to compare cards for matchplayer.h


private:
	Suit m_suit; // private storage of suit
	friend std::ostream& operator<<(std::ostream& os, MatchCard &c);	//bool operator<(MatchCard &compare);
	int _Rank;	//shows max rank
};
