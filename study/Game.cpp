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
	player->init();
}

void Game::Update() {
	board->Update();
	time->Update();
	player->Update();

}

void Game::Render() {
	//system("cls");
	board->Render();
	time->Render();
	player->Render();
}

void Game::Destroy()
{
	board->Destroy();
	time->Destroy();
	player->Destroy();
	delete board;
	delete time;
	delete player;
}
