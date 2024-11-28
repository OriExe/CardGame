#pragma once
#include <vector>
#include "card.h"

using std::vector;
using std::endl;
class card; // <- Declaration of class to ensure program knows it exists
class player {
private:
	int health = 20;
	player* opponent = nullptr;
	vector<card*> deck; 
	vector<card*> hand;
	vector<card*> discord_pile;
public:
	player() {} //A default constructor??
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

	/// <summary>
	/// Sets opponent of player
	/// </summary>
	/// <param name="opp"></param>
	void setOpponent(player* opp)
	{
		if (opp != this && opponent != nullptr)
		{
			opponent = opp;
			std::cout << "Opponent Set" << endl;
		}
	}
};

