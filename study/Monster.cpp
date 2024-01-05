#include "Monster.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::init()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> random_pos_x(1, BoardX-1);
	std::uniform_int_distribution<int> random_pos_y(1, BoardY-1);
	pos = { random_pos_x(gen), random_pos_y(gen) };
}

void Monster::Update()
{

}

void Monster::Render()
{
	gotoxy(pos.x * 2, pos.y);
	std::cout << "ес";
}

void Monster::Destroy()
{

}
