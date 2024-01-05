#pragma once
#include "Common.h"
#include "Player.h"
#include "Board.h"
#include "Timer.h"
#include "Monster.h"

class Game {

public:
	Game();
	~Game();	
	void init();
	void Update();
	void Render();
	void Destroy();
	bool IsNeedDestroy() { return player->Getkey() == ESCAPE; };
private:
	Player* player = new Player;
	Board* board = new Board;
	Timer* time = new Timer;
	Monster* monster = new Monster;
	//int board[BoardY][BoardX];
};

