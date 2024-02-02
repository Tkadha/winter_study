#include "Ghost.h"

Ghost::Ghost() : Monster()
{
	gold = 50;
	exp = 5;
}

Ghost::~Ghost()
{
}

void Ghost::Init(int inid)
{
	id = inid;
	gotoxy(0, BoardY + 11);
	std::cout << "G = Ghost";
}

void Ghost::Update()
{
	Monster::Update();
}

void Ghost::Render()
{
	if (hp > 0) {
		gotoxy(pos.x * 2, pos.y);
		std::cout << "G";
	}
}

void Ghost::Destroy()
{
}
