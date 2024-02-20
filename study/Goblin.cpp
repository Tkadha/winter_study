#include "Goblin.h"

Goblin::Goblin() : Monster()
{
	type = Type::Type_Goblin;
	hp = 3;
	gold = 100;
	exp = 20;
	drop_item = Data::items[Item_Code::Goblin_ear];
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
