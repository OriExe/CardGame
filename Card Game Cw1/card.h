#pragma once
#include <iostream>
#include "player.h"

using std::cout;
using std::string;

class player;
class card {
private:

public:
	virtual string getName()
	{
		return "";
	}
	virtual void effect(player* p)
	{

	}

	/// <summary>
	/// Returns how much of one card they should be in the player's deck
	/// Example 5 painful lesson in each deck
	/// </summary>
	/// <returns></returns>
	virtual int getAmount()
	{
		return 0;
	}
};

