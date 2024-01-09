#pragma once
#include "Common.h"
#include "Timer.h"

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
	Timer* time = Timer::GetInstance();
	int input;
	int command;
	int key;
};

