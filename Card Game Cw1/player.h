#pragma once
#include <vector>
#include "card.h"


using std::vector;
using std::endl;
class card; // <- Declaration of class to ensure program knows it exists
//void card::effect(player* p);
extern void shuffle(vector<card*>& cards); //Declaration of function inside main C++ file // Reference https://learn.microsoft.com/en-us/cpp/cpp/extern-cpp?view=msvc-170

class player {
private:
	int health = 20;
	player* opponent = nullptr;
	vector<card*> deck; 
	vector<card*> discord_pile;
protected:
	vector<card*> hand;
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
	void drawCard() ///Draw a card from their deck
	{
		//If their deck is empty return false;
		if (deck.size() == 0)
		{
			health = 0;
		}
		else
		{
			hand.push_back(deck.front());
			deck.erase(deck.begin());
		}
	}
	/// <summary>
	/// Removes the card from the player's hand and moves it to the discard pile 
	/// </summary>
	/// <param name="index">Takes an index to make it easier to remove the value</param>
	card* playCard(int index) 
	{
		if (hand.size() != 0)
		{
			card* temp = hand[index];
			discord_pile.push_back(hand[index]);
			hand.erase(hand.begin() + index); //I'm not sure why this isn't working
			return temp;
		}
		else
		{
			card* dummy = new card();
			return dummy;
		}
		
	}
	virtual int myTurn() = 0;
	bool hasLost()
	{
		if (health <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
#pragma region Getters
	int getHealth()
	{
		return health;
	}
	/// <summary>
	/// Sets opponent of player
	/// </summary>
	/// <param name="opp"></param>
	player* getOpponent()
	{
		return opponent;
	}

	vector<card*> getHand()
	{
		return hand;
	}
	virtual bool isHuman() = 0;

#pragma endregion
	/// <summary>
	/// Should only run in the beginnig of the function
	/// </summary>
	/// <param name="opp"></param>
	void setOpponent(player* opp)
	{
		if (opponent == nullptr)
		{
			opponent = opp;
			std::cout << "Opponent Set" << endl;
		}
	}
	
#pragma region Card Functions
	//Fully heals the player
	void fullHeal()
	{
		health = 20;
	}

	/// <summary>
	/// To be used with switchroo class
	/// </summary>
	/// <param name="TempHand"></param>
	/// <param name="n">Makes the function only run twice</param>
	void swapHands(vector<card*> TempHand, int n = 1)
	{

		if (n > 0) //If not 0 
		{
			opponent->swapHands(hand, 0); //Becomes 0 and doesn't run again
		}
		hand = TempHand;
	}

	void rebootDeck()
	{
		for (card* DeadCard : discord_pile)
		{
			deck.push_back(DeadCard);
		}
		discord_pile.clear();
		shuffle(deck);
	}

	void getFirstCardName()
	{
		if (deck.size() != 0)
		{
			std::cout << "Opponent has " << deck[0]->getName() << " in their deck" << endl;
		}
	}

#pragma endregion

};

