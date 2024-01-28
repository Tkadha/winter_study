#pragma once
#include "Common.h"
#include "Input.h"
#include "Object.h"

enum Level {
	Level_1 = 10,
	Level_2 = 20,
	Level_3 = 30,
	Level_4 = 45,
	Level_5 = 70,
	Level_6 = 90,
	Level_7 = 100,
	Level_8 = 120,
	Level_9 = 150,
	Level_10 = 99999999,
};

class Player : public Object{
public:
	~Player();
	Player();
	Player(const Player& other);
	static Player* GetInstance();

	virtual void Init(int inid) override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
	virtual int Getid() override;

public:
	static bool attack;
	static Pos attackpoint;
private:
	static Player* instance;
	int way;
	int attack_count;
	bool see_attack;

	int level;
	int exp;
	int hp, mp;
	int gold;
	int power;
};

