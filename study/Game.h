#pragma once
#ifndef __Game_h__
#define __Game_h__
#include "Player.h"


class Game {
public:
	Player player;

	void init();
	void Update();
	void Render();

};

#endif // !__Game_h__
