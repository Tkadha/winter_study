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
			case SPACE:		// ��ȣ�ۿ�/Ȯ��

				break;
			case D:			// ����				
				break;
			case ESCAPE:		// �ڷΰ��� or ���α׷� ����
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
	std::cout << "��";
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

