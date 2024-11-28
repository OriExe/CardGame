#pragma once
#include "player.h"
#include "card.h"
#include <vector>

using std::vector;
using std::endl;
class card;
class ComputerPlayer : public player
{
public:
	ComputerPlayer(vector<card*> deck) : player(deck)
	{
		cout << "Computer Played added" << endl;
	}
	void myTurn()
	{
		//Do something
	}
};

