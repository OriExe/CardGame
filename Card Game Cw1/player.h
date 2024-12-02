#pragma once
#include <vector>
#include "card.h"


using std::vector;
using std::endl;
class card; // <- Declaration of class to ensure program knows it exists
//void card::effect(player* p);
extern vector<card*> shuffle(vector<card*> cards); //Declaration of function inside main C++ file // Reference https://learn.microsoft.com/en-us/cpp/cpp/extern-cpp?view=msvc-170

class player {
private:
	int health = 20;
	player* opponent = nullptr;
	vector<card*> deck; 
	vector<card*> discard_pile; 
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
		if (hand.size() > 0)
		{
			card* temp = hand[index];
			discard_pile.push_back(hand[index]); //Puts in discard pile
			hand.erase(hand.begin() + index);  //Removes from player's hand
			return temp; //Returns card type to play that card
		}
		else //Runs if player has no cards left 
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

	/// <summary>
	/// Gets the player's current hand
	/// </summary>
	/// <returns></returns>
	vector<card*> getHand()
	{
		return hand;
	}
	/// <summary>
	/// Is the player human controlled?
	/// </summary>
	/// <returns></returns>
	virtual bool isHuman() = 0;

#pragma endregion
	/// <summary>
	/// Should only run in the beginning of the function
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
	/// <summary>
	/// Fully heals the player
	/// </summary>
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

	/// <summary>
	/// Puts their discard pile back in their deck and shuffles it
	/// </summary>
	void rebootDeck()
	{
		for (card* DeadCard : discard_pile)
		{
			deck.push_back(DeadCard);
		}
		discard_pile.clear();
		deck = shuffle(deck);
	}
	/// <summary>
	/// Returns the first card in the opponents deck
	/// </summary>
	void getFirstCardName()
	{
		if (deck.size() != 0)
		{
			std::cout << "Opponent has " << deck[0]->getName() << " in their deck" << endl;
		}
	}

#pragma endregion

};

