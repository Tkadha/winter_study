#include "Game.h"


Game::Game()
{

}

Game::~Game()
{

}

void Game::init() {
	board.init();
	player.init();
}

void Game::Update() {
	board.Update();
	player.Update();

}

void Game::Render() {
	//system("cls");
	board.Render();
	player.Render();
}

void Game::Destroy()
{
	board.Destroy();
	player.Destroy();
}
