#pragma once
#include <ctime>
#include "Common.h"

class Timer
{
public:
	Timer();
	~Timer();

	void init();
	void Update();
	void Render();
	void Destroy();
private:
	time_t start, finish;
	double clock;
	double min;
	double sec;
};

