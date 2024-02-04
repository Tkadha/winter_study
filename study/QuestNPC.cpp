#include "QuestNPC.h"
unsigned int QuestNPC::open = 0;
QuestNPC::QuestNPC() :NPC()
{
}

QuestNPC::~QuestNPC()
{
}

void QuestNPC::Init()
{
}

void QuestNPC::Update()
{
	if (Input::input) {
		if (Input::key == Q) {
			open++;
		}
	}
}

void QuestNPC::Render()
{
	gotoxy(pos.x * 2, pos.y);
	std::cout << "¨Ú";
}

void QuestNPC::Destroy()
{
}
