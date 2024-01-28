#include "Goblin.h"

Goblin::Goblin() : Monster()
{
	hp = 2;
}

Goblin::~Goblin()
{
}

void Goblin::Init(int inid)
{
	id = inid;
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
