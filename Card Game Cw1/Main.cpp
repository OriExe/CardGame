#include <iostream>
#include <vector>
#include <random>
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
/// Shuffles the players deck
/// </summary>
/// <param name="cards">Reference to current deck</param>

extern void shuffle(vector<card*>& cards)
{
	//This is not that random tho
	auto rng = std::default_random_engine{};
	std::shuffle(cards.begin(), cards.end(), rng);
	cout << "Deck shuffled" << endl;
}


int main()
{
	//Create deck for both the player and computer
	createDeck(playerDeck);
	createDeck(computerDeck);
	//Shuffle Deck
	shuffle(playerDeck);
	shuffle(computerDeck);
	
	//Creates players and sets the opponent value
	HumanPlayer* player = new HumanPlayer(playerDeck);
	ComputerPlayer* aiPlayer = new ComputerPlayer(computerDeck);
	player->setOpponent(aiPlayer);
	aiPlayer->setOpponent(player);
	
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