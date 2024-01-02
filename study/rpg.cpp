#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Game.h"

Game game;

int main() {
	game.init();
	while (1) {
		game.Render();
		game.Update();
		system("cls");
	}
	return 0;
}