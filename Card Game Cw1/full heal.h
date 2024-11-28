#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class fullHeal : public card {
private:

public:
	string getName()
	{
		return "Full Heal";
	}
	void effect(player* p)
	{

	}
	int getAmount()
	{
		return 1;
	}
};

