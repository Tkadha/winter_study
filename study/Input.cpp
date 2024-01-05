#include "Input.h"

Input::Input()
{
	
}

Input::~Input()
{

}

void Input::init()
{
	key = 0;
	input = 0;
	command = 0;
}

void Input::Update()
{
	input = _kbhit();
	if (input) {
		command = _getch();
		switch (command)
		{
		case ESCAPE:		//프로그램 종료
			key = command;
			break;
		case WAVE:
			gotoxy(0, BoardY);
			std::cout << "Press Enter to continue..." << std::endl;
			while (!_kbhit());
			gotoxy(0, BoardY);
			std::cout << "                            " << std::endl;
			break;
		default:
			break;
		}
	}
}

void Input::Render()
{
}

void Input::Destroy()
{
}

int Input::Getkey()
{
	return key;
}

int Input::Getinput()
{
	return input;
}

int Input::Getcommand()
{
	return command;
}

