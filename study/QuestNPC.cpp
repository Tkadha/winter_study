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
			if (open > 0) {
				open--;
				gotoxy(BoardX * 7 / 3, 10);
				std::cout << "                                                                                  ";
				gotoxy(BoardX * 7 / 3, 11);
				std::cout << "                                                                                  ";
				gotoxy(BoardX * 7 / 3, 12);
				std::cout << "                                                                                  ";
			}
			else {
				open++;                                                        
			}
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
