#include "Game.h"


Game::Game()
{
	for(int i=0;i<mob_count;++i)
		monsters.push_back(new Monster);
}

Game::~Game()
{

}

void Game::init() {
	board->init();
	time->init();
	player->init();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> random_pos_x(1, BoardX - 2);
	std::uniform_int_distribution<int> random_pos_y(1, BoardY - 2);
	std::uniform_int_distribution<int> move_delay(1, 5);
	for (Monster* i : monsters) {
		Pos pos = { random_pos_x(gen), random_pos_y(gen) };
		int delay = move_delay(gen);
		i->init(pos, delay, Mob_id++);
	}
}

void Game::Update() {
	board->Update();
	time->Update();
	player->Update();
	for (Monster* i : monsters) {
		i->Update();
	}
}

void Game::Render() {
	board->Render();
	time->Render();
	for (Monster* i : monsters) {
		i->Render();
		//gotoxy(BoardX, BoardY);
		//std::cout << i->Getcount() << " ";
	}
	player->Render();
}

void Game::Destroy()
{
	board->Destroy();
	time->Destroy();
	player->Destroy();
	for (Monster* i : monsters) {
		i->Destroy();
		delete i;
	}
	delete board;
	delete time;
	delete player;
}


