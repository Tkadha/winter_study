#pragma once
#include "Common.h"
#include "Input.h"
#include "Object.h"



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
	void Setexp(int a);
	int Getexp();
	void Setgold(int b);
	int Getgold();
	void State_Render();
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

