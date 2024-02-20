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

 if (state[quest_id] == 0) {
	 gotoxy(BoardX * 7/3, 40);
	 cout << "                                                                         ";
	 gotoxy(BoardX * 7 / 3, 41);
	 cout << "                                                                         ";
	 gotoxy(BoardX * 7 / 3, 42);
	 cout << "                                                                         ";
	
	 gotoxy(BoardX * 7 / 3, 40);
	 cout << questtitle[quest_id];
	 gotoxy(BoardX * 7 / 3, 41);
	 cout << questscript[quest_id];
	 gotoxy(BoardX * 7 / 3, 42);
	 cout << questreward[quest_id];
 }


}
void Quest::Render2() {
	for (int i = 0; i < 5; i++) {
		if (state[i] == 1) {
			gotoxy(BoardX * 7 / 3, 40);
			cout << questtitle[i];
			gotoxy(BoardX * 7 / 3, 41);
			cout << questscript[i];
			gotoxy(BoardX * 7 / 3, 42);
			cout << questreward[i];
		}
	}
}

void Quest::Update()
{
	if (Input::input) {
		
		if (Input::key == E) {
			if (4 > quest_id) {
				if (state[quest_id + 1] == 1) {
					quest_id += 2;
				}
				else {
					quest_id++;
				}
			}
		}
		else if (Input::key == W) {
			if (quest_id > 0) {
				if (state[quest_id - 1] == 1) {
					quest_id -=2;
				}
				else {
					quest_id--;
				}
			}
		}
		else if (Input::key == P) {
			state[quest_id] = 1;
		}
		else if (Input::key == K) {
			for (int i = 0; i < 5; i++) {
				if (state[i] == 1) {
					p->Setexp(reward[i].exp);
					p->Setgold(reward[i].gold);
					break;
				}
			}
		}
	}
}
