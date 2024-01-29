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
	//Data::quests.emplace_back(new )
	Data::objects.emplace_back(new Player);
	Data::objects[Data::user_id]->Init(Data::user_id);
	for (int i = 0; i < mob_count; ++i) {
		Data::objects.emplace_back(new Ghost);
		Data::objects[Data::global_id]->Init(Data::global_id);
		++Data::global_id;
	}
	for (int i = 0; i < mob_count; ++i) {
		Data::objects.emplace_back(new Goblin);
		Data::objects[Data::global_id]->Init(Data::global_id);
		++Data::global_id;
	}
}

void Game::Update() {
	board->Update();
	time->Update();
	input->Update();
	quest->Update();
	for (Object* obj : Data::objects) {
		obj->Update();
	}
}

void Game::Render() {
	board->Render();
	time->Render();
	quest->Render();
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


