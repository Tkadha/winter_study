#pragma once
#include "Common.h"
#include "Input.h"





class Player {
public:
	~Player();
	Player();
	Player(const Player& other);
	static Player* GetInstance();

	void init();
	void Update();
	void Render();
	void Destroy();

	Pos Getpos();
	int Getkey();
	bool DoAttack();
	Pos GetAttackPoint();
private:
	static Player* instance;

	Input in;
	Pos pos;
	Pos attackpoint;
	int way;
	bool attack;
	int attack_count;
	bool see_attack;
	int command;
};

