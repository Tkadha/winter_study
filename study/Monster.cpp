#include "Monster.h"
int Monster::id = 1000;

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::Init(int inid)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> random_pos_x(1, BoardX - 2);
	std::uniform_int_distribution<int> random_pos_y(1, BoardY - 2);
	std::uniform_int_distribution<int> move_delay(1, 5);
	pos = { random_pos_x(gen),random_pos_y(gen) };
	delay_count = move_delay(gen) * 3;
	move_count = 0;
	id = inid;
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
		Pos P_pos = Data::objects[Data::user_id]->Getpos();
		if (range > abs(pos.x - P_pos.x) + abs(pos.y - P_pos.y)) {	//
			if (abs(pos.x - P_pos.x) > abs(pos.y - P_pos.y)) {	//
				if (pos.x < P_pos.x) {	//
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
	if(Player::attack)
		CheckHit();
}

void Monster::Render()
{
	if (hp > 0) {
		gotoxy(pos.x * 2, pos.y);
		std::cout << "��";
	}
}

void Monster::Destroy()
{

}

int Monster::Getid()
{
	return id;
}



bool Monster::CheckHit()
{
	Pos playerpos = Player::attackpoint;
	if ((pos.x == playerpos.x) && (pos.y == playerpos.y))
		hp--;

	if (hp < 1)
		return true;
	else
		return false;
}
