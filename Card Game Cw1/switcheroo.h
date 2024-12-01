#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class player;
class switchroo : public card {
private:

public:
	string getName()
	{
		return "Switcheroo";
	}
	void effect(player& p)
	{
		p.swapHands(p.getOpponent()->getHand()); //Gives the oppnent their deck
	}
	int getAmount()
	{
		return 2;
	}
	string getHelp()
	{
		return "swaps the contents of your hand with your opponent";
	}
};

