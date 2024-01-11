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

static int input;
static int command;
static int key;
	
private:
	Timer* time = Timer::GetInstance();
};

