#pragma once
#include <iostream>
#include <vector>
#include <string>
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

	/// <summary>
	/// Runs code that lets the player take their turn
	/// </summary>
	/// <returns>Returns index of the card they picked in their hand</returns>
	int myTurn()
	{
		//Prints all cards in the player's hand
		for (int i = 0; i < hand.size(); i++)
		{
			cout << i << ":" << hand[i]->getName() << endl;
		}

		cout << "Pick a card to play" << endl;
		string query = "";
		std::cin >> query;
		int index = std::stoi(query); //Converts string to int
		if (index >= 0 && index < hand.size()) // <- Is index in range
		{
			if (query == std::to_string(index) + "/?")
			{
				cout << "--" << hand[index]->getHelp() <<  "--" << endl; // <- Returns card info
			}
			else
			{
				return index; //Plays card on opponent  triggering it's effect
			}
		}
		else
		{
			cout << "This is out of the range" << endl;
		}
		myTurn();
		
	}

	bool isHuman()
	{
		return true;
	}
};

