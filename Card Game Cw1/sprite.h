#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class player;
class spite : public card {
private:

public:
	string getName()
	{
		return "Spite";
	}
	void effect(player& p)
	{
		p.loseHeath(1);
		p.getOpponent()->loseHeath(1);
		cout << "You have both lost 1 hp" << endl;
	}
	int getAmount()
	{
		return 6;
	}
	string getHelp()
	{
		return "both players lose 1 health";
	}
};

