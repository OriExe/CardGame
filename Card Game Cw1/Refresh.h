#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class player;
class refresh : public card {
private:

public:
	string getName()
	{
		return "Refresh";
	}
	void effect(player& p)
	{
		p.getOpponent()->loseHeath(3); //Gets the player that played the card 
		p.getOpponent()->rebootDeck();
	}
	int getAmount()
	{
		return 2;
	}
	string getHelp()
	{
		return "lose 3 health and shuffle your discard pile back into your deck.";
	}
};

