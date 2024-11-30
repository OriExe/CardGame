#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class refresh : public card {
private:

public:
	string getName()
	{
		return "Refresh";
	}
	void effect(player* p)
	{

	}
	int getAmount()
	{
		return 2;
	}
	virtual string getHelp()
	{
		return "lose 3 health and shuffle your discard pile back into your deck.";
	}
};

