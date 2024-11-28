#pragma once
#include <iostream>
#include <vector>
#include "player.h"

using std::vector;
using std::endl;
class card;
//class card; // <- Declaration of class to ensure program knows it exists
class HumanPlayer : public player
{
private: 

public:
	//Constructor for the player Sends the deck to the player class
	HumanPlayer(vector<card*> newDeck) : player(newDeck) 
	{
		cout << "Human Played added" << endl;
	}
	void myTurn()
	{
		//Do something
	}
};

