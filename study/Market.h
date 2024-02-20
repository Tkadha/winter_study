#pragma once
#include "Common.h"
#include "Input.h"
#include "Data.h"
#include "Player.h"
using namespace std;
class Market
{
public:
	Market();
	~Market();
	void Init();
	void Update();
	void Render();
	void RenderSell();
	void Destroy();
private:
	string temp_name;
	int temp_price;
	int arrow = 0;
	int player_gold = 0;
	Player* p = Player::GetInstance();
	
};

