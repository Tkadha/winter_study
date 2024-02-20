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
				open = 0;
				gotoxy(BoardX * 7 / 3, 40);
				std::cout << "                                                                                  ";
				gotoxy(BoardX * 7 / 3, 41);
				std::cout << "                                                                                  ";
				gotoxy(BoardX * 7 / 3, 42);
				std::cout << "                                                                                  ";
			}
			else {
				open = 1;                                                        
			}
		}
		else if (Input::key == J) {
			if (open > 0) {
				open = 0;
				gotoxy(BoardX * 7 / 3, 40);
				std::cout << "                                                                                  ";
				gotoxy(BoardX * 7 / 3, 41);
				std::cout << "                                                                                  ";
				gotoxy(BoardX * 7 / 3, 42);
				std::cout << "                                                                                  ";
			}
			else {
				open = 2;
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
