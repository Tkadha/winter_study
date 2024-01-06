#pragma once
#include "Common.h"
#include <random>

enum Move {
	Move_UP,
	Move_DOWN,
	Move_LEFT,
	Move_RIGHT,
};

class Monster
{
	
public:
	Monster();
	~Monster();
	void init(Pos position, int delay, int num);
	void Update();
	void Render();
	void Destroy();
	int Getcount();
private:
	Pos pos;
	int delay_count;
	int move_count;
	int id;
};



