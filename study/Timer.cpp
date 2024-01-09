#include "Timer.h"

Timer* Timer::instance = nullptr;

Timer::Timer()
{
	
}

Timer::~Timer()
{

}

Timer::Timer(const Timer& other)
{
}

Timer* Timer::GetInstance()
{
	if (instance == NULL)
		instance = new Timer();
	return instance;
}

time_t Timer::Getfin()
{
	return finish;
}

void Timer::Setstart(time_t fin)
{
	start = fin;
}

void Timer::init()
{
	start = time(NULL);
	finish = time(NULL);
	clock = (double)(finish - start);
	min = (int)clock / 60;
	sec = (int)clock % 60;
}

void Timer::Update()
{
	finish = time(NULL);
	clock += (double)(finish - start);
	start = finish;
}

void Timer::Render()
{
	if ((int)clock % 60 == 0) {
		gotoxy(BoardX * 3, 0);
		std::cout << "                           ";
	}
	min = (int)clock / 60;
	sec = (int)clock % 60;
	gotoxy(BoardX * 3, 0);
	std::cout << "실행시간: " << min << "분" << sec << "초";
}

void Timer::Destroy()
{

}

void Timer::TimerRestart()
{
	start = time(NULL);
	finish = time(NULL);
}
