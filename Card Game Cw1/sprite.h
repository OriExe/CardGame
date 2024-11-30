#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class sprite : public card {
private:

public:
	string getName()
	{
		return "Sprite";
	}
	void effect(player* p)
	{

	}
	int getAmount()
	{
		return 6;
	}
	virtual string getHelp()
	{
		return "both players lose 1 health";
	}
};

