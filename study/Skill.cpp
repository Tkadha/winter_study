#include "Skill.h"

Skill::Skill() : range{ 1 }, skill_type{ Skill_type::Circle } , skill_count{0}
{
	Set_Hit_Box();
}

Skill::~Skill()
{
}

void Skill::Set_Center(Pos obj_pos)
{
	center = obj_pos;
}

void Skill::Render()
{
	for (Pos pos : hit_point)
	{
		gotoxy(pos.x*2, pos.y);
		if (skill_count == 0) std::cout << "□" << std::endl;
		else if (skill_count == 1) std::cout << "▩" << std::endl;
	}
	++skill_count;
	if (skill_count > 1) skill_count = 0;
}
void Skill::Erase_Render()
{
	for (Pos pos : hit_point)
	{
		gotoxy(pos.x * 2, pos.y);
		std::cout << "  " << std::endl;
	}
}
void Skill::Set_Hit_Box()
{
	hit_point.clear();
	if (skill_type == Skill_type::Cross_X) {
		for (int i = center.y - range; i <= center.y + range; ++i) {
			for (int j = center.x - range; j <= center.x + range; ++j) {
				if ((i == center.y) || (j == center.x)) continue;
				Pos hit_box = { j,i };
				hit_point.emplace_back(hit_box);
			}
		}	// 사거리가 늘어났을때 모양 수정해야함
	}
	else if (skill_type == Skill_type::Cross) {
		for (int i = center.y - range; i <= center.y + range; ++i) {
			for (int j = center.x - range; j <= center.x + range; ++j) {
				
			}
		}
	}
	else if (skill_type == Skill_type::Circle) {
		for (int i = center.y - range; i <= center.y + range; ++i) {
			for (int j = center.x - range; j <= center.x + range; ++j) {
				if ((i == center.y) && (j == center.x)) continue;
				Pos hit_box = { j,i };
				hit_point.emplace_back(hit_box);
			}
		}
	}
}
