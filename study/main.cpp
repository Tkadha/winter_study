#define  _CRT_SECURE_NO_WARNINGS
#include "Common.h"
#include "Game.h"
#include "Input.h"


int main() {
	SetConsoleTitle(TEXT("Winter Study - Console Game"));
	Game* game = new Game;
	game->Init();

	while (true) {
		game->Update();
		game->Render();
		Sleep(100);
		if (Input::key == ESCAPE) break;
	}

	game->Destroy();
	delete game;
	return 0;
}