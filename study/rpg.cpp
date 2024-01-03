#define  _CRT_SECURE_NO_WARNINGS
#include "Common.h"
#include "Game.h"


int main() {
	Game* game = new Game;
	game->init();

	while (true) {
		game->Update();
		game->Render();
		Sleep(100);

		if (game->IsNeedDestroy()) break;
	}

	game->Destroy();
	delete game;
	return 0;
}