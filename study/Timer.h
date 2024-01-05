#pragma once
#include <ctime>
#include "Common.h"

class Timer
{
public:
	Timer();
	~Timer();
	time_t Getfin();
	void Setstart(time_t);
	void init();
	void Update();
	void Render();
	void Destroy();
	void TimerRestart();
private:
	time_t start, finish;
	double clock;
	double min;
	double sec;
};

