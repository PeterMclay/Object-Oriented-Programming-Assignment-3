#include <iostream>
#include "MatchCard.h"
using namespace std;

MatchCard::MatchCard()
{
}

MatchCard::MatchCard(Suit suit, int Rank)	//constructor set suit and rank
{
	m_suit = suit;
	_Rank = Rank;
}

MatchCard::~MatchCard()	//destructor
{
}
char MatchCard::toCharSuit()	//shows denomintations for suit
{
	if (m_suit == HEARTS)   return 'H';
	else if (m_suit == CLUBS)    return 'C';
	else if (m_suit == SPADES)   return 'S';
	else                       return 'D';
}

bool MatchCard::operator<(const MatchCard &compare) const	//overloaded < compares the rank and suit
{
	if (this->_Rank < compare._Rank) {
		return true;
	}
	else if (this->_Rank == compare._Rank)
	{
		if (this->m_suit < compare.m_suit)
		{
			return true;
		}
	}
	return false;
}


std::ostream& operator<<(std::ostream& os, MatchCard &c)	//overloaded << that prints card
{	
	int suit = c.getSuit();
	int demo = c.getrank();
	if (demo == 1) {
		os << "Ace";
	}
	else
	{
		os << demo;
	}
	switch (suit) {
	case 1:
		os << " of Spades";
		break;
	case 2:
		os << " of Hearts";
		break;
	case 3:
		os << " of Clubs";
		break;
	default:
		os << " of Diamonds";
	}
	return os;
}
