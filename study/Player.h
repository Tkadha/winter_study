#pragma once
#include "Common.h"
#include "Input.h"
#include "Object.h"
#include "Skill.h"
#include "Inventory.h"



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
	int Getgold();
	void Setgold(int b);
	void Set_Hp(int h);
	int Get_Power();
	int Get_Level();
	void State_Render();
	Skill Get_Skill();

	void Regen_State();
	void Upgrade_State();
public:
	static bool attack;
	static Pos attackpoint;
	static bool skill_on;
	Inventory inven;

private:
	static Player* instance;
	int way;
	int attack_count;
	bool see_attack;

	int level;
	int hp, mp;
	int max_hp, max_mp;

	Skill skill;
	int skill_count;

	int hp_level, mp_level, range_level, power_level;

};

