#pragma once
#include <iostream>
#include "player.h"

using std::cout;
using std::string;

class player;
class card {
private:

public:
	/// <summary>
	/// Gets the name of the card the player wants to play
	/// </summary>
	/// <returns></returns>
	virtual string getName()
	{
		return "";
	}
	/// <summary>
	/// Plays the effect on the character
	/// </summary>
	/// <param name="p"></param>
	virtual void effect(player* p)
	{

	}

	/// <summary>
	/// Gets help for whatever card the player wants to play
	/// </summary>
	/// <returns></returns>
	virtual string getHelp()
	{
		return "";
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

