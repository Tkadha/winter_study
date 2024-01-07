#pragma once
#include "Common.h"
#include "Input.h"





class Player {
public:
	Player();
	~Player();
	void init();
	void Update();
	void Render();
	void Destroy();

	Pos Getpos();
	int Getkey();
	bool DoAttack();
	Pos GetAttackPoint();
private:
	Input in;
	Pos pos;
	Pos attackpoint;
	int way;
	bool attack;
	int attack_count;
	bool see_attack;
	int command;
};

