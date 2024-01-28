#pragma once
#include <random>
#include "Common.h"
#include "Player.h"
#include "Data.h"
enum Move {
	Move_UP,
	Move_DOWN,
	Move_LEFT,
	Move_RIGHT,
};

class Monster : public Object
{
public:
	Monster();
	~Monster();
	virtual void Init(int inid);
	virtual void Update();
	virtual void Render();
	virtual void Destroy();
	virtual int Getid();

	void CheckHit();
protected:
	int delay_count;
	int move_count;
	int hp;
	int range;
	int power;
	int invincibility_time;
	bool invincibility;
};



