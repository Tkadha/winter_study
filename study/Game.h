#pragma once
#include "Common.h"
#include "Player.h"
#include "Board.h"
#include "Timer.h"

class Game {
Player *player = new Player;
Board *board = new Board;
Timer *time = new Timer;
public:

	Game();
	~Game();
	void init();
	void Update();
	void Render();
	void Destroy();

	bool IsNeedDestroy() { return player->key == ESCAPE; };
};

