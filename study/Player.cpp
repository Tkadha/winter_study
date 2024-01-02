#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Player.h"


#define BoardX 15
#define BoardY 15

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define D 100
#define ESCAPE 27


void Player::init() {
	x = 1;
	y = 1;
}
void Player::Update() {
		int command;
		command = _getch();
		//std::cout << command << std::endl;
		if (command == 224) {
			command = _getch();
			switch (command)
			{
			case UP:
				if (y > 1)
					y--;
				break;
			case DOWN:
				if (y < BoardY - 2)
					y++;
				break;
			case LEFT:
				if (x > 1)
					x--;
				break;
			case RIGHT:
				if (x < BoardX - 2)
					x++;
				break;
			default:
				break;
			}
		}
		else {
			switch (command)
			{
			case SPACE:		// 상호작용/확인

				break;
			case D:			// 공격				
				break;
			case ESCAPE:		// 뒤로가기 or 프로그램 종료
				system("cls");
				exit(0);
				break;
			default:
				break;
			}
		}
	}

