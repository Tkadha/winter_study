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
			if (check == 1) {
				questtitle.emplace_back(file);
			}
			else if (check == 2) {
				questscript.emplace_back(file);
			}
			else {
				questreward.emplace_back(file);
				check = 0;
			}
			check++;
			
		}
		questfile.close();
	}
	check = 1;
	questfile.open("reward.txt");
	if (questfile.is_open())
	{
		while (!questfile.eof())
		{
			getline(questfile, store);
			if (check % 2 == 1) {
				reward[id].exp = stoi(store);
			}
			else {
				reward[id].gold = stoi(store);
				id++;
			}
			check++;
		}
	}
}

void Quest::Render()
{
	gotoxy(BoardX * 7/3, 10);
	cout << "                                                                        ";
	gotoxy(BoardX * 7/3, 10);
	cout << questtitle[quest_id];
	gotoxy(BoardX * 7 / 3, 11);
	cout << questscript[quest_id];
	gotoxy(BoardX * 7 / 3, 12);
	cout << questreward[quest_id];

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
			if(4>quest_id)
			quest_id++;
		}
		else if (Input::key == W) {
			if(quest_id>0)
			quest_id--;
		}
	}
}
