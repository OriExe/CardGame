#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class peek : public card {
private:

public:
	string getName()
	{
		return "Peek";
	}
	void effect(player* p)
	{

	}

	int getAmount()
	{
		return 4;
	}
	virtual string getHelp()
	{
		return "look at the top cards of both players’ decks";
	}
};

