#include "Skill.h"

Skill::Skill() : range{ 2 }, skill_type{ Skill_type::Cross_X } , skill_count{0}
{
	center = { 4,4 };
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
		if (skill_count == 0) std::cout << "бр" << std::endl;
		else if (skill_count == 1) std::cout << "в╠" << std::endl;
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
		int x_point = center.x - range;
		for (int i = center.y - range; i <= center.y + range; ++i) {
			Pos hit_box = { x_point,i };
			++x_point;
			if ((i == center.y) || (x_point-1 == center.x)) continue;
			if ((i < 1) || (i > BoardY - 1) || (x_point-1 < 1) || (x_point-1 > BoardX - 1)) continue;
			hit_point.emplace_back(hit_box);
		}
		x_point = center.x - range;
		for (int i = center.y + range; i >= center.y - range; --i) {
			Pos hit_box = { x_point,i };
			++x_point;
			if ((i == center.y) || (x_point - 1 == center.x)) continue;
			if ((i < 1) || (i > BoardY - 1) || (x_point - 1 < 1) || (x_point - 1 > BoardX - 1)) continue;
			hit_point.emplace_back(hit_box);
		}		
	}
	else if (skill_type == Skill_type::Cross) {
		for (int i = center.y - range; i <= center.y + range; ++i) {
			if (i == center.y) continue;
			if ((i < 1) || (i > BoardY - 1)) continue;
			Pos hit_box = { center.x,i };
			hit_point.emplace_back(hit_box);
		}
		for (int i = center.x - range; i <= center.x + range; ++i) {
			if (i == center.x) continue;
			if ((i < 1) || (i > BoardX - 1)) continue;
			Pos hit_box = { i,center.y };
			hit_point.emplace_back(hit_box);
		}
	}
	else if (skill_type == Skill_type::Circle) {
		for (int i = center.y - range; i <= center.y + range; ++i) {
			for (int j = center.x - range; j <= center.x + range; ++j) {
				if ((i == center.y) && (j == center.x)) continue;
				if ((i < 1) || (i > BoardY - 1) || (j < 1) || (j > BoardX - 1)) continue;
				Pos hit_box = { j,i };
				hit_point.emplace_back(hit_box);
			}
		}
	}
}

std::vector<Pos> Skill::Get_Hit_Point()
{
	return hit_point;
}
