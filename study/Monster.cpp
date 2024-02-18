#include "Monster.h"

Monster::Monster() : move_count{0},hp{1},range{5}, regeneration{ false }, regeneration_time{ 0 }
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> random_pos_x(1, BoardX - 2);
	std::uniform_int_distribution<int> random_pos_y(1, BoardY - 2);
	std::uniform_int_distribution<int> move_delay(1, 5);
	pos = { random_pos_x(gen),random_pos_y(gen) };
	delay_count = move_delay(gen) * 3;
}

Monster::~Monster()
{
}

void Monster::Init(int inid)
{	
	id = inid;
}

void Monster::Update()
{
	if (regeneration) {
		++regeneration_time;
		if (regeneration_time > 30) {
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> random_pos_x(1, BoardX - 2);
			std::uniform_int_distribution<int> random_pos_y(1, BoardY - 2);
			std::uniform_int_distribution<int> move_delay(1, 5);
			pos = { random_pos_x(gen),random_pos_y(gen) };
			delay_count = move_delay(gen) * 3;
			move_count = 0;
			invincibility = false;
			invincibility_time = 0;

			regeneration = false;
			regeneration_time = 0;
			if (exp == 10)	// 몬스터 종류 구분
				hp = 2;
			else
				hp = 1;
		}
		return;
	}
	if (move_count < delay_count)
		++move_count;
	else
	{
		gotoxy(pos.x * 2, pos.y);
		std::cout << "  ";
		Pos P_pos = Data::objects[Data::user_id]->Getpos();
		if (range > abs(pos.x - P_pos.x) + abs(pos.y - P_pos.y)) {	// 플레이어가 범위안에 있으면
			if (abs(pos.x - P_pos.x) > abs(pos.y - P_pos.y)) {	// x값의 차이가 더 크다면
				if (pos.x < P_pos.x) {
					if (pos.x < BoardX - 2) {
						pos.x++;
						way = Move_RIGHT;
					}
				}
				else if (pos.x > P_pos.x) {
					if (pos.x > 1) {
						pos.x--;
						way = Move_LEFT;
					}
				}
				else {
					if (pos.y < P_pos.y) {
						if (pos.y < BoardY - 2) {
							pos.y++;
							way = Move_DOWN;
						}
					}
					else if (pos.y > P_pos.y) {
						if (pos.y > 1) {
							pos.y--;
							way = Move_UP;
						}
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
		else {	// 범위 밖이라면 랜덤이동
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<int> ran_way(0, 3);
			way = ran_way(gen);
			switch (way) {
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
	Pos P_pos = Data::objects[Data::user_id]->Getpos();
	if (P_pos == pos) {	// 위치가 같으면 몸통박치기
		p->Set_Hp(power);
	}
	if (Player::attack)
		CheckHit(Type_Attack);
	if (Player::skill_on)
		CheckHit(Type_Skill);
	if (invincibility)
		++invincibility_time;
	if (invincibility_time > 10)
		invincibility = false;
	
}

void Monster::Render()
{

}

void Monster::Destroy()
{

}

int Monster::Getid()
{
	return id;
}



void Monster::CheckHit(int type)
{
	if (invincibility) return;
	bool hit = false;
	if (type == Type_Attack) {
		Pos playerpos = Player::attackpoint;
		if ((pos.x == playerpos.x) && (pos.y == playerpos.y)) {
			hit = true;
		}
	}
	else if (type == Type_Skill) {
		Skill skill = p->Get_Skill();
		std::vector<Pos> points = skill.Get_Hit_Point();
		for (Pos point : points)
			if ((pos.x == point.x) && (pos.y == point.y))
				hit = true;			
	}
	if (!hit) return;
	hp--;
	invincibility = true;
	move_count = 0;
	switch (way) {
	case Move_UP:
		if (pos.y < BoardY - 2)
			pos.y++;
		break;
	case Move_DOWN:
		if (pos.y > 1)
			pos.y--;
		break;
	case Move_LEFT:
		if (pos.x < BoardX - 2)
			pos.x++;
		break;
	case Move_RIGHT:
		if (pos.x > 1)
			pos.x--;
		break;
	default:
		break;
	}
	if (hp < 1) {
		p->Setexp(exp);
		p->Setgold(gold);
		regeneration = true;
	}
}


