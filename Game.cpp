#include <iostream>
#include "Player.h"
#include "Game.h"

#define BoardX 15
#define BoardY 15

void Game::init() {
	player.init();
}

void Game::Update() {
	player.Update();
}

void Game::Render() {
	for (int i = 0; i < BoardY; ++i) {
		for (int j = 0; j < BoardX; ++j) {
			if (i == 0 || j == 0 || i == BoardY - 1 || j == BoardX - 1) {
				std::cout << "бс";
			}
			else if (i == player.y && j == player.x) {
				std::cout << "в├";
			}
			else
				std::cout << "  ";
		}
		std::cout << std::endl;
	}
}