#include "Timer.h"

Timer::Timer()
{
	start = time(NULL);
	finish = time(NULL);
	clock = (double)(finish - start);
	min = (int)clock / 60;
	sec = (int)clock % 60;
}

Timer::~Timer()
{

}

void Timer::init()
{

}

void Timer::Update()
{
	finish = time(NULL);
	clock = (double)(finish - start);
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
