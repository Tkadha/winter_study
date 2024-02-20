#include "Game.h"
Game::Game()
{

}

Game::~Game()
{

}

void Game::Init() {

	board->init();
	time->Init();
	input->Init();
	quest->Init();
	quest_npc->Init();

	Item* store= nullptr;
	callitem.open("itemname.txt");
	if (callitem.is_open())
	{
		while (!callitem.eof())
		{
			std::getline(callitem, file);
			if (check == 0) {
				store = new Item;
				store->Get_Name(file);
				check++;
			}
			else if (check == 1) {
				store->Get_Price(stoi(file));
				check++;
			}
			else if (check == 2) {
				store->Get_Ability(stoi(file));
				check = 0;

				Data::items.emplace_back(store);
			}
		}
		callitem.close();
	}

	Data::objects.emplace_back(new Player);
	Data::objects[Data::user_id] = Player::GetInstance();
	Data::objects[Data::user_id]->Init(Data::user_id);
	Object* Temp{};
	for (int i = 0; i < mob_count; ++i) {
		Temp = new Ghost;
		Data::objects.emplace_back(Temp);
		Data::objects[Data::global_id]->Init(Data::global_id);
		++Data::global_id;
		Temp = new Goblin;
		Data::objects.emplace_back(Temp);
		Data::objects[Data::global_id]->Init(Data::global_id);
		++Data::global_id;
	}
	
}

void Game::Update() {
	board->Update();
	time->Update();
	input->Update();
	quest->Update();
	quest_npc->Update();
	for (Object* obj : Data::objects) {
		obj->Update();
	}
}

void Game::Render() {
	board->Render();
	time->Render();
	quest_npc->Render();
	if (QuestNPC::open == 1) {
		quest->Render();
	}
	else if (QuestNPC::open == 2) {
		quest->Render2();
	}
	
	for (Object* obj : Data::objects) {
		if (obj->Getid() == Data::user_id)
			continue;
		else
			obj->Render();
	}
	Data::objects[Data::user_id]->Render();
}

void Game::Destroy()
{
	
}


