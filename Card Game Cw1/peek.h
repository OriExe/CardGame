#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class player;
class peek : public card {
private:

public:
	string getName()
	{
		return "Peek";
	}
	void effect(player& p)
	{
		//player* temp;
		if (p.isHuman() == true)
		{
			 p.getOpponent()->getFirstCardName(); ///Get the name of the card in the computer's deck
		}
		else
		{
			p.getFirstCardName();
		}
	}

	int getAmount()
	{
		return 4;
	}
	string getHelp()
	{
		return "look at the top cards of both players decks";
	}
};

