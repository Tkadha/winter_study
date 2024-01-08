#include "Monster.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::init(Pos position, int delay, int num)
{
	
	pos = position;
	delay_count = delay * 3;
	move_count = 0;
	id = num;
	hp = 1;
	range = 7;
}

void Monster::Update()
{
	if (move_count < delay_count)		
		++move_count;
	else
	{
		gotoxy(pos.x * 2, pos.y);
		std::cout << "  ";
		Pos P_pos = player->Getpos();
		int P_to_M_range;
		P_to_M_range = abs(pos.x - P_pos.x) + abs(pos.y - P_pos.y);
		if (range > P_to_M_range) {
			if (abs(pos.x - P_pos.x) > abs(pos.y - P_pos.y)) {
				if (pos.x < P_pos.x) {
					if (pos.x < BoardX - 2)
						pos.x++;
				}
				else if (pos.x > P_pos.x) {
					if (pos.x > 1)
						pos.x--;
				}
				else {
					if (pos.y < P_pos.y) {
						if (pos.y < BoardY - 2)
							pos.y++;
					}
					else if (pos.y > P_pos.y) {
						if (pos.y > 1)
							pos.y--;
					}
				}
			}
			else {
				if (pos.y < P_pos.y) {
					if (pos.y < BoardY - 2)
						pos.y++;
				}
				else if (pos.y > P_pos.y) {
					if (pos.y > 1)
						pos.y--;
				}
				else {
					if (pos.x < P_pos.x) {
						if (pos.x < BoardX - 2)
							pos.x++;
					}
					else if (pos.x > P_pos.x) {
						if (pos.x > 1)
							pos.x--;
					}
				}
			}
			move_count = 0;
		}
		else {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> way(0, 3);
			switch (way(gen)) {
			case Move_UP:
				if (pos.y > 1)
					pos.y--;
				break;
			case Move_DOWN:
				if (pos.y < BoardY - 2)
					pos.y++;
				break;
			case Move_LEFT:
				if (pos.x > 1)
					pos.x--;
				break;
			case Move_RIGHT:
				if (pos.x < BoardX - 2)
					pos.x++;
				break;
			default:
				break;
			}
			move_count = 0;
		}
	}
	if(player->DoAttack())
		CheckHit();
}

void Monster::Render()
{
	if (hp > 0) {
		gotoxy(pos.x * 2, pos.y);
		std::cout << "ес";
	}
}

void Monster::Destroy()
{

}

bool Monster::CheckHit()
{
	Pos playerpos = player->GetAttackPoint();
	if ((pos.x == playerpos.x) && (pos.y == playerpos.y))
		hp--;

	if (hp < 1)
		return true;
	else
		return false;
}

