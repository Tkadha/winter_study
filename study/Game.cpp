#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::init() {
	board->init();
	time->init();
	input->init();


	Data::objects.emplace_back(new Player);
	Data::objects[Data::user_id]->init(Data::user_id);
	for (int i = 0; i < mob_count; ++i) {
		Data::objects.emplace_back(new Monster);
		Data::objects[Data::global_id]->init(Data::global_id);
		++Data::global_id;
	}
}

void Game::Update() {
	board->Update();
	time->Update();
	input->Update();
	for (Object* obj : Data::objects) {
		obj->Update();
	}
}

void Game::Render() {
	board->Render();
	time->Render();
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


