#pragma once
#include "Common.h"
#include "Input.h"





class Player {
public:
	Player();
	~Player();
	Pos Getpos();
	int Getkey();
	void init();
	void Update();
	void Render();
	void Destroy();
private:
	Input in;
	Pos pos;
	int way;
	bool attack;
	int attack_count;
	bool see_attack;
	int command;
};

