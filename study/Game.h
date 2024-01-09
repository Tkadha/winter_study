#pragma once
#include "Common.h"
#include "Player.h"
#include "Board.h"
#include "Timer.h"
#include "Monster.h"

#define mob_count 3
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
	Player* player = Player::GetInstance();
	Board* board = new Board;
	Timer* time = Timer::GetInstance();
	std::vector<Monster* > monsters;
	int Mob_id = 0;
	//int board[BoardY][BoardX];
};

