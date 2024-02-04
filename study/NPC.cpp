#include "NPC.h"

NPC::NPC()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> random_pos_x(1, BoardX - 2);
	std::uniform_int_distribution<int> random_pos_y(1, BoardY - 2);
	std::uniform_int_distribution<int> move_delay(1, 5);
	pos = { random_pos_x(gen),random_pos_y(gen) };
}

NPC::~NPC()
{
}

void NPC::Init(int inid)
{
}

void NPC::Update()
{
}

void NPC::Render()
{
	
}
void NPC::Destroy()
{
}

int NPC::Getid()
{
	return 0;
}
