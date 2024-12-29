#pragma once
#include "player.h"
#include "card.h"
#include <vector>
#include <random>
#include <Windows.h>

using std::vector;
using std::endl;
class card;
class ComputerPlayer : public player
{
private:
	std::default_random_engine engine;
public:
	ComputerPlayer(vector<card*> deck) : player(deck)
	{
		cout << "Computer Played added" << endl;
	}
	int myTurn()
	{
		//Random Number generator I've used in a previous project of mine
		std::uniform_int_distribution<int> RandomInt(0, hand.size()); //Generates a random Number
		int randomIndex = RandomInt(engine);
		Sleep(2000); //Windows specific sleep function  Guide in this link --> https://www.geeksforgeeks.org/sleep-function-in-cpp/
		if (randomIndex == hand.size())
		{
			if (hand.size() < 5) //Will only actually draw card if computer has less than 5 cards
			{
				cout << "Computer has drawn a card" << endl;
				drawCard();
			}
			return myTurn();
		}
		else
		{
			cout << "Computer has played " << hand[randomIndex]->getName() << endl; 
			return randomIndex;
		}
	}

	bool isHuman()
	{
		return false;
	}
};

