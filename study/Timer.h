#pragma once
#include <ctime>
#include "Common.h"

class Timer
{
public:
	Timer();
	~Timer();

	Timer(const Timer& other);
	static Timer* GetInstance();

	time_t Getfin();
	void Init();
	void Update();
	void Render();
	void Destroy();

	void Setstart(time_t);
	void TimerRestart();
private:
	static Timer* instance;

	time_t start, finish;
	double clock;
	double min;
	double sec;
};

