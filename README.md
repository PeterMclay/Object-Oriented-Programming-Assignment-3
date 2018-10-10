# Object-Oriented-Programming-Assignment-3
Your Task:
In this assignment you will create a simulation of an card game called MATCH between multiple players. These players however are not very smart (or at least don’t have to be).

The Game:
-Cards consist of a standard deck without face cards (No jacks, queens, or kings).
-Each card has a suit (diamond, spade, heart, club).
-Each card has a rank (1 through MAX) - Aces are 1. (Maximum ranks is specified by the user)
-Total of 4 x MAX cards

Game Simulation:
-The user will specify the number of players (numPlayers)
-The user will specify the maximum rank (maxRank)
-At the start of the game numPlayers player objects will be created
-An array of cards will be created consisting of ALL (4 x maxRank) the cards of the deck
-Cards will be taken randomly from the array(until empty) and placed into a Queue that represents the deck pile
-6 cards for each player will then be taken from the deck pile and placed into the hand of each of the each player. The hand of each      player must be an OrderedList
-1 card will be taken from the deck pile and placed into the faceup pile. The faceup pile must be a Stack
-You will then loop UNTIL the game is finished (the game is finished when a player has no cards left in their hand) each player will have a turn. 

A turn consists of the following:
-Check to see if they have a card in their hand with the same rank as the card on the top of the face up pile. If true take that card out of their hand and place it on the face up pile.
-If the above fails check to see if they have a card in their hand the same suit as the card on top of the face up pile. If true take that card out of their hand and place it on the face up pile
-If both of the above fail draw a card from the deck pile (the hand will grow by one the deck will shrink by 1 after this action.
-If the deck pile runs out of cards take and save the top of the faceup pile. Then place all cards in the facedown pile into the deck pile. -Finally place the card you saved back on top of the faceup pile. After this is complete the faceup pile will contain just a singular card.
-Check to see if the player has 1 card lef
-Finally check to see the player has 0 cards left and is the winner of the game

After a player's turn is finished you must transfer control to next player and repeat the steps above until a player has 0 cards left.
