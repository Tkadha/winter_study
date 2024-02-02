#include "Goblin.h"

Goblin::Goblin() : Monster()
{
	hp = 2;
	gold = 100;
	exp = 10;
}

Goblin::~Goblin()
{
}

void Goblin::Init(int inid)
{
	id = inid;
	gotoxy(0, BoardY + 10);
	std::cout << "O = Goblin";
}

void Goblin::Update()
{
	Monster::Update();
}

void Goblin::Render()
{
	if (hp > 0) {
		gotoxy(pos.x * 2, pos.y);
		std::cout << "O";
	}
}

void Goblin::Destroy()
{
}
