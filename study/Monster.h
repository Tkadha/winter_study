#pragma once
#include <random>
#include "Common.h"
#include "Player.h"

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
	bool CheckHit();
private:
	Player* player = Player::GetInstance();
	Pos pos;
	int delay_count;
	int move_count;
	int id;
	int hp;
	int range;
};



