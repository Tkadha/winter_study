#include "Game.h"


Game::Game()
{

}

Game::~Game()
{

}

void Game::init() {
	player.init();
	board.init();
	board.Render();
}

void Game::Update() {
	player.Update();
	board.Update();

}

void Game::Render() {
	//system("cls");
	player.Render();
}

void Game::Destroy()
{
	board.Destroy();
	player.Destroy();
}
