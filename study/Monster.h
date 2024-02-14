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

enum Attack_Type {
	Type_Attack,
	Type_Skill
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

	void CheckHit(int);
protected:
	int delay_count;
	int move_count;
	int hp;
	int range;
	int power;
	int way;
	Player* p = Player::GetInstance();

	int invincibility_time;
	bool invincibility;

	bool regeneration;
	int regeneration_time;
};



