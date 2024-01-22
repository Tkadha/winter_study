#pragma once
#include "Common.h"
#include "Player.h"
#include "Board.h"
#include "Timer.h"
#include "Monster.h"
#include "Input.h"
#include "Data.h"

const int mob_count = 3;
class Game {

public:
	Game();
	~Game();	
	void Init();
	void Update();
	void Render();
	void Destroy();

private:
	Board* board = new Board;
	Input* input = new Input;
	Timer* time = Timer::GetInstance();

	//int board[BoardY][BoardX];
};

