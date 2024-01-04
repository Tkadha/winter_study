#pragma once
#include "Common.h"

#define ESCAPE 27

class Player {
public:
	int x;
	int y;
	int key;
	Player();
	~Player();

	void init();
	void Update();
	void Render();
	void Destroy();
private:
	int way;
	bool attack;
	int attack_count;
	bool see_attack;
};

