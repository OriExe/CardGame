#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class player;
class fullHeal : public card {
private:

public:
	string getName()
	{
		return "Full Heal";
	}
	void effect(player& p)
	{
		p.getOpponent()->fullHeal(); //The opponent in this case would be the player that called the function
		if (p.getOpponent()->isHuman() == true)
		{
			cout << "You have fully healed!" << endl;
		}
		else
		{
			cout << "They have fully healed!" << endl;
		}
	}
	int getAmount()
	{
		return 1;
	}
	 string getHelp()
	{
		return "restores your health back to 20";
	}
};

