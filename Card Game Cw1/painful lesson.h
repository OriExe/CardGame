#pragma once
#include <iostream>
#include "card.h"
#include "player.h"
using std::cout;
using std::string;

class painfulLesson : public card{
private:

public:
	string getName()
	{
		return "Painful Lesson";
	}
	void effect(player* p)
	{

	}
	int getAmount()
	{
		return 5;
	}
};

