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
}

void Monster::Update()
{
	if (move_count < delay_count)		
		++move_count;
	else
	{
		gotoxy(pos.x * 2, pos.y);
		std::cout << "  ";
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

void Monster::Render()
{
	gotoxy(pos.x * 2, pos.y);
	std::cout << "ес";
}

void Monster::Destroy()
{

}

int Monster::Getcount()
{
	return move_count;
}
