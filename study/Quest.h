#pragma once
#include "Common.h"
#include <string>

struct Reward {
	int gold;
	int exp;
};

class Quest
{
	unsigned long long id;
	Reward reward;
	std::string script;	
};

