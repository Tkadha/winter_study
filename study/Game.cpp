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
	monster->init();
}

void Game::Update() {
	board->Update();
	time->Update();
	player->Update();
	monster->Update();
}

void Game::Render() {
	board->Render();
	time->Render();
	monster->Render();
	player->Render();
}

void Game::Destroy()
{
	board->Destroy();
	time->Destroy();
	player->Destroy();
	monster->Destroy();
	delete board;
	delete time;
	delete player;
	delete monster;
}


