#include "MatchPlayer.h"

std::ostream & operator<<(std::ostream & os, const MatchPlayer & c)	//prints players name
{
	int n = c.getNumber();
	os << "Player ";
	os << n;
	return os;
}


MatchPlayer::MatchPlayer()
{
	//Nothing needed in constructor
}

MatchPlayer::~MatchPlayer()
{
}

int MatchPlayer::matchFindRank(MatchCard upCard) //compares the rank with the card passed in with the players hand. If there is a match return the position of the card in the hand
{
	int length = pHand.getLength();
	for (int i = 1; i <= length; i++)
	{
		MatchCard place_holder = pHand.retrieve(i);
		if (place_holder.getrank() == upCard.getrank())
		{
			return i;
		}
	}
	return -1;	//If no match return -1
}

int MatchPlayer::matchFindSuit(MatchCard upCard)	////compares the suit with the card passed in with the players hand. If there is a match return the position of the card in the hand
{
	int length = pHand.getLength();
	for (int i = 1; i <= length; i++)
	{
		MatchCard place_holder = pHand.retrieve(i);
		if (place_holder.getSuit() == upCard.getSuit())
		{
			return i;
		}
	}
	return -1;	//returns -1 if no match
}

void MatchPlayer::draw(MatchCard card)
{
	pHand.insert(card);	//inserts card into hand
}

MatchCard MatchPlayer::showHand(int num)	//shows card and position hand
{
	return pHand.retrieve(num);	
}

MatchCard MatchPlayer::discardCard(int index)	//removes card at position index
{
	return pHand.remove(index);	
}
