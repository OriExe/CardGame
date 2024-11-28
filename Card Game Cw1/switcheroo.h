#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class switchroo : public card {
private:

public:
	string getName()
	{
		return "Switcheroo";
	}
	void effect(player* p)
	{

	}
	int getAmount()
	{
		return 2;
	}
};

