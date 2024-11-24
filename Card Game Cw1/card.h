#pragma once
#include <iostream>
#include "player.h"

using std::cout;
using std::string;

class player;
class card {
private:

public:
	virtual string getName()
	{

	}
	virtual void effect(player* p)
	{

	}
};

