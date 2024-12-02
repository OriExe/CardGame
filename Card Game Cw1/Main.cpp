#include <iostream>
#include <vector>
#include <cstdlib> // Needed to generate a random number 
#include <ctime>   // Needed to get time info
#include <algorithm>
#include "card.h"
#include "player.h"
//All player subclassess
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
//All cards subclasses
#include "peek.h"
#include "full heal.h"
#include "painful lesson.h"
#include "Refresh.h"
#include "sprite.h"
#include "switcheroo.h"

using std::cout;
using std::string;
using std::endl;
using std::vector;

class card;
vector<card*> playerDeck;
vector<card*> computerDeck;

void drawCard()
{

}


/// <summary>
///Creates all card classes and put 3 of each card in a deck
/// </summary>
/// <param name="cards">Reference to current deck</param>
void createDeck(vector<card*>& cards)
{
#pragma region Create Cards

	fullHeal* healCard = new fullHeal();
	painfulLesson* painfulLessonCard = new painfulLesson();
	peek* peakCard = new peek();
	refresh* refreshCard = new refresh();
	spite* spriteCard = new spite();
	switchroo* switchRooCard = new switchroo();

#pragma endregion

	//All types of cards
	card* allCards[6] = { healCard, painfulLessonCard, peakCard, refreshCard, spriteCard, switchRooCard };

	//Puts the cards in the player's deck with the correct amount
	for (card* pCard : allCards)
	{
		for (int i = 0; i < pCard->getAmount(); i++)
		{
			cards.push_back(pCard);
		}
	}
	cout << "Deck created" << endl;
}

/// <summary>
/// Shuffles the players deck and returns it
/// </summary>
/// <param name="cards">Reference to current deck</param>
extern vector<card*> shuffle(vector<card*> cards)
{
	vector<card*> temp; 
	vector<int> usedIndexes; //Already used cards

	srand(time(0)); //Generates a random seed based on the current time //Reference https://www.w3schools.com/cpp/cpp_howto_random_number.asp
	while (temp.size() != cards.size())
	{
		bool nonDuplicate = true;
		int randomIndex = rand() % cards.size(); // Generate a random number between 0 and the number of cards in the deck 
		//If index already used will it will not be used again
		for (int i : usedIndexes)
		{
			if (i == randomIndex)
			{
				nonDuplicate = false;
			}
		}
		if (nonDuplicate == true) //Only runs if the index is unique to the new deck 
		{
			temp.push_back(cards[randomIndex]);
			usedIndexes.push_back(randomIndex);
		}
	}

	return temp;
}


int main()
{
	//Create deck for both the player and computer
	createDeck(playerDeck);
	createDeck(computerDeck);
	//Shuffles each Deck
	playerDeck = shuffle(playerDeck);
	computerDeck = shuffle(computerDeck);
	
	//Creates players and sets the opponent values
	HumanPlayer* player = new HumanPlayer(playerDeck);
	ComputerPlayer* aiPlayer = new ComputerPlayer(computerDeck);
	player->setOpponent(aiPlayer);
	aiPlayer->setOpponent(player);
	
	//Draws 5 cards
	cout << "Drawing cards" << endl;
	for (int i = 0; i < 5; i++)
	{
		player->drawCard();
		aiPlayer->drawCard();
	}

	//Start of game loop
	cout << "Welcome to the London Card game, type the number of the card you want to play that card /nif you need help then add \"/?\" to your answer (For example \"1/?\") \nIf your deck runs out of cards you lose" << endl;
	int playerIndex = 0;
	int computerIndex = 0;
	while (player->hasLost() == false && aiPlayer->hasLost() == false)
	{
		cout << "Your deck:" << "	Health:" << player->getHealth() << "	Opponent Health:" <<aiPlayer->getHealth() << endl;
		playerIndex = player->myTurn(); 
		player->playCard(playerIndex)->effect(*aiPlayer);
		//
		computerIndex = aiPlayer->myTurn();
		aiPlayer->playCard(computerIndex)->effect(*player);
	}

	//End of game loop
	if (player->hasLost() == true)
	{
		cout << "You have lost :(" << endl;
	}
	else
	{
		cout << "Congrats you win!" << endl;
	}
	return 0;
}