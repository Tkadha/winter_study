#include "Player.h"



Player::Player()
{
	x = 1;
	y = 1;
}

Player::~Player()
{

}

void Player::init() {

}

void Player::Update() {
	int input = _kbhit();
	if (input) {
		gotoxy(x * 2, y);
		std::cout << "  ";
		int command = _getch();
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
				key = command;
				break;
			default:
				break;
			}
		}
	}
}

void Player::Render()
{

	gotoxy(x * 2, y);
	std::cout << "▣";
	gotoxy(0, BoardY);
}

void Player::Destroy()
{
}

void Player::gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

