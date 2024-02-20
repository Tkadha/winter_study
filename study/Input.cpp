#include "Input.h"
int Input::input = 0;
int Input::command = 0;
int Input::key = 0;
Input::Input()
{
	
}

Input::~Input()
{

}

void Input::Init()
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
		if (command == 224) {
			command = _getch();
			key = command;
		}
		else {
			switch (command)
			{
			case ESCAPE:		//프로그램 종료
				key = command;
				break;
			case WAVE:
				key = command;
				gotoxy(0, BoardY*5/3);
				std::cout << "Press Enter to continue..." << std::endl;
				while (!_kbhit());
				time->TimerRestart();
				gotoxy(0, BoardY);
				std::cout << "                            " << std::endl;
				break;
			default:
				key = command;
				break;
			}
		}
	}
}

void Input::Render()
{
}

void Input::Destroy()
{
}



