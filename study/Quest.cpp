#include "Quest.h"
#include "Input.h"

void Quest::Init()
{
	questfile.open("quest.txt");
	if (questfile.is_open())
	{
		while (!questfile.eof())
		{
			std::getline(questfile, file);
			script.emplace_back(file);
		}
		questfile.close();
	}
}

void Quest::Render()
{
	gotoxy(BoardX * 7/3, 10);
	cout << "                                                                                  ";
	gotoxy(BoardX * 7/3, 10);
	cout << script[quest_id];
}

void Quest::Update()
{
	if (Input::input) {
		if (Input::key == Q) {
			if (open == 0) {
				open = 1;
			}
			else {
				open = 0;
			}
		}
		else if (Input::key == E) {
			if(quest_id+1<script.size())
			quest_id++;
		}
		else if (Input::key == W) {
			
			quest_id--;
		}
	}
}
