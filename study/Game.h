#pragma once
#
#include "Common.h"
#include "Player.h"
#include "Board.h"
#include "Timer.h"
#include "Input.h"
#include "Data.h"
#include "Ghost.h"
#include "Goblin.h"
#include "QuestNPC.h"
#include "Item.h"

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
	Quest* quest = new Quest;
	QuestNPC* quest_npc = new QuestNPC;
	Timer* time = Timer::GetInstance();
	
	std::ifstream callitem;
	string item_name;
	string file;
	int check = 0;
	//int board[BoardY][BoardX];
};

