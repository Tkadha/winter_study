#pragma once
#include "Common.h"
#include <random>

class Monster
{
	
public:
	Monster();
	~Monster();
	void init();
	void Update();
	void Render();
	void Destroy();
private:
	Pos pos;
};


