#pragma once
#include "Common.h"

class Input
{
public:
	Input();
	~Input();
	void init();
	void Update();
	void Render();
	void Destroy();

	int Getkey();
	int Getinput();
	int Getcommand();
private:
	int input;
	int command;
	int key;
};

