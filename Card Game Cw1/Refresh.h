#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class refresh : public card {
private:

public:
	string getName()
	{
		return "Refresh";
	}
	void effect(player* p)
	{

	}
	int getAmount()
	{
		return 2;
	}
};

