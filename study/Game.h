#pragma once
#include "Common.h"
#include "Player.h"
#include "Board.h"


class Game {
Player player;
Board board;
int key;
public:

	Game();
	~Game();
	void init();
	void Update();
	void Render();
	void Destroy();

	bool IsNeedDestroy() { return player.key == ESCAPE; };
};

