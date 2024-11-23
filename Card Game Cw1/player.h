#include <iostream>
#include <vector>
#include "card.h"

using std::vector;
#pragma once
class player {
private:
	int health = 20;
	player* opponent;
	vector<card*> deck; vector<card*> hand; vector<card*> discord_pile;
public:
	void loseHeath(int i)
	{
		health -= i;
	}
	bool drawCard()
	{
		//If their deck is empty return false;
		if (deck.size() == 0)
		{
			return false;
		}
		else
		{
			//Draws card
			return true;
		}
	}
	void playCard(card *c)
	{
		//Play card 
	}
	virtual void myTurn()
	{
		
	}
	bool hasLost()
	{
		///Losing condition
	}
};

