#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class player;
class painfulLesson : public card{
private:

public:
	string getName()
	{
		return "Painful Lesson";
	}
	void effect(player& p)
	{
		p.loseHeath(2);
		p.drawCard();
		cout << "It was very effective" << endl;
	}
	int getAmount()
	{
		return 5;
	}
	string getHelp()
	{
		return "opponent loses 2 health and must draw a card";
	}
};

