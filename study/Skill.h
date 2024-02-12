#pragma once
#include "Common.h"
#include "Object.h"
enum class Skill_type{
	Cross_X,
	Cross,
	Circle
};


class Skill
{
public:
	Skill();
	~Skill();

	void Set_Center(Pos);
	void Render();
	void Erase_Render();
	void Set_Hit_Box();
private:
	Skill_type skill_type;
	int range;
	std::vector<Pos> hit_point;
	Pos center;
	int skill_count;
};

