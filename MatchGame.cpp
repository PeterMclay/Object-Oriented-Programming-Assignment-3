#include "MatchGame.h"
#include "MatchPlayer.h"
#include <ctime>

MatchGame::MatchGame(int num_players, int max_rank) : Player(new MatchPlayer[num_players]) //Creates all cards and places into an array
{
	NumPlayers = num_players;
	MaxRank = max_rank;
	_array = new MatchCard[(MaxRank * 4)];

	MatchCard *arrayh = new MatchCard[MaxRank];	//Creates array of hearts
	for (int i = 0; i < MaxRank; i++)
	{
		arrayh[i] = MatchCard(HEARTS, i + 1);
	}
	for (int i = 0; i < MaxRank; i++)
	{
		_array[i] = arrayh[i];
	}

	MatchCard *arrays = new MatchCard[MaxRank]; //Creates array of spades
	for (int i = 0; i < MaxRank; i++)
	{
		arrays[i] = MatchCard(SPADES, i + 1);
	}
	int a = 0;
	for (int i = MaxRank; i < (MaxRank * 2); i++)
	{
		_array[i] = arrays[a];
		a++;
	}

	MatchCard *arrayd = new MatchCard[MaxRank];	//Creates array of diamonds
	for (int i = 0; i < MaxRank; i++)
	{
		arrayd[i] = MatchCard(DIAMONDS, i + 1);
	}
	int b = 0;
	for (int i = (MaxRank * 2); i < (MaxRank * 3); i++)
	{
		_array[i] = arrayd[b];
		b++;
	}

	MatchCard *arrayc = new MatchCard[MaxRank]; //Creates array of clubs
	for (int i = 0; i < MaxRank; i++)
	{
		arrayc[i] = MatchCard(CLUBS, i + 1);
	}
	int c = 0;
	for (int i = (MaxRank * 3); i < (MaxRank * 4); i++)
	{
		_array[i] = arrayc[c];
		c++;
	}
	
	//Randomizing Cards
	tmp = new MatchCard[MaxRank * 4];
	srand(time(NULL));
	for (int x = 0; x < (MaxRank * 4); x++)
	{
		//chose a random index from our tmp array of VALID data
		int ix = rand() % ((MaxRank * 4) - x);
		tmp[x] = _array[ix];
		//move the last element in our tmp array to the remove element position
		_array[ix] = _array[(MaxRank * 4) - x - 1];
	}
	
	//Queue<MatchCard> 
	Deck_Pile = MaxRank * 4;	//QUEUE
	Face_up_pile = MaxRank * 4;	//STACK
	
	//Putting Cards In the Queue
	for (int i = 0; i < MaxRank * 4; i++)	
	{
		Deck_Pile.enqueue(tmp[i]);
	}
	cout << endl;
	
	//GIVING PLAYERS 6 CARDS EACH
	cout << "Giving players their cards" << endl;
	for (int i = 0; i < NumPlayers; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			MatchCard place_holder = Deck_Pile.dequeue();
			Player[i].draw(place_holder);
		}
	}
	cout << endl;

	//SETTING PLAYER NAME
	for (int i = 0; i < NumPlayers; i++)
	{
		Player[i].setNumber(i);
	}

	//PUTTING FIRST CARD INTO FACE UP PILE
	MatchCard temp = Deck_Pile.dequeue();
	Face_up_pile.push(temp);
	cout << endl;
}

MatchGame::~MatchGame()	//destructor
{
	delete[]_array;
	delete[]tmp;
	delete[] Player;
}

void MatchGame::play()
{
	cout << "|******************* Starting a Game of MATCH *******************|" << endl;
	cout << "|________________________________________________________________|" << endl;
	cout << endl;
	int x = 1;
	while (x != 0)
	{	
		for (int i = 0; i < NumPlayers; i++)
		{
			cout << endl;
			cout << "Face up card is: |" << Face_up_pile.peek() << "|" << endl; cout << endl;	//prints face up card
			cout << Player[i] << "'s turn: " << endl;	//prints whos turn
			cout << Player[i] << "'s hand: ";
			for (int j = 1; j <= Player[i].getHandSize(); j++)
			{
				cout << "|"<<Player[i].showHand(j) << "|";
			}
			cout << endl;
			int find_index_rank = Player[i].matchFindRank(Face_up_pile.peek());
			int find_index_suit = Player[i].matchFindSuit(Face_up_pile.peek());
			if (find_index_rank != -1)	//checks match of hand rank and face up rank
			{
				cout << Player[i] << " found a match! They played " << Player[i].showHand(find_index_rank) << endl;
				Face_up_pile.push(Player[i].discardCard(find_index_rank));
				if (Player[i].getHandSize() == 1)	//checks if player has one card left
				{
					cout << Player[i] << " has one card left!" << endl; 
				}
				if (Player[i].getHandSize() == 0)	//checks if player has one card left
				{
					cout << "CONGRATULATIONS! " << Player[i] << " won the game!" << endl;
					x = 0;
					break;
				}
			}
			else if (find_index_suit != -1)	//checks match of hand suit and face up suit
			{
				cout << Player[i] << " found a match! They played "<<Player[i].showHand(find_index_suit)<< endl;
				Face_up_pile.push(Player[i].discardCard(find_index_suit));
				if (Player[i].getHandSize() == 1)
				{
					cout << Player[i] << " has one card left!" << endl;
				}
				if (Player[i].getHandSize() == 0)
				{
					cout << "CONGRATULATIONS! " << Player[i] << " won the game!" << endl;
					x = 0;
					break;
				}
			}
			else
			{
				MatchCard place_holder = Deck_Pile.dequeue(); //Sets place holder = to card in queue
				Player[i].draw(place_holder); //Adds card into hand
				cout << Player[i] << " did not find a match. They drew " << place_holder << endl;
				if (Deck_Pile.isEmpty() == 1)	//If the queueu is now empty repopulate it
				{
					cout << "The deck has been repopulated" << endl;
					MatchCard plc_holder = Face_up_pile.pop();	//saves face up card
					for (int i = 0; i <= Face_up_pile.getfront(); i++) //moves cards from stack into queue
					{
						Deck_Pile.enqueue(Face_up_pile.pop());
					}
					Face_up_pile.push(plc_holder);
				}
			}
		}
	}
}

