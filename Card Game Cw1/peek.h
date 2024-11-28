#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class peek : public card {
private:

public:
	string getName()
	{
		return "Peek";
	}
	void effect(player* p)
	{

	}

	int getAmount()
	{
		return 4;
	}
};

