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
	virtual void init(int inid) override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
	virtual int Getid() override;

	bool CheckHit();
private:
	int delay_count;
	int move_count;
	static int id;
	int hp;
	int range;
};



