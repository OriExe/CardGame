#pragma once
#include <vector>
#include "card.h"

using std::vector;
class card; // <- Declaration of class to ensure program knows it exists
class player {
private:
	int health = 20;
	player* opponent;
	vector<card*> deck; 
	vector<card*> hand;
	vector<card*> discord_pile;


public:
	player(vector<card*> newDeck)
	{
		deck = newDeck;
	}
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
			//Draws card*
			return true;
		}
	}
	void playCard(card* c)
	{
		//Play card* 
	}
	virtual void myTurn()
	{
		
	}
	bool hasLost()
	{
		///Losing condition
	}

	void setOpponent(player* opp)
	{
		if (opp != this)
		{
			opponent = opp;
		}
	}
};

