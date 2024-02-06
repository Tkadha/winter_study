#pragma once
#include "Common.h"
#include "Player.h"
#include <string>
#include <fstream>
#include <vector>
using namespace std;
struct Reward {
	int gold;
	int exp;
};

class Quest
{
 public:
	
	Reward reward[5];
	string file;
	vector<string> questtitle;
	vector<string> questscript;
	vector<string> questreward;
	int state[5];
	Player* p = Player::GetInstance();
	void Init();
	void Render();
	void Render2();
	void Update();
 private:
	std::ifstream questfile;
	int line = 0;
	int count = 0;
	int open = 0;
	int quest_id = 0;
	int id = 0;
	int check = 1;
	int player_exp = 0;
	int player_gold = 0;
	string store;
};

