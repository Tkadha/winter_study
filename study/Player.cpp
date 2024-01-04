#include "Player.h"



Player::Player()
{
	x = 1;
	y = 1;
	attack = false;
	attack_count = 0;
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
			if (attack) {
				switch (way) {
				case UP:
					gotoxy(x * 2, y - 1);
					break;
				case DOWN:
					gotoxy(x * 2, y + 1);
					break;
				case LEFT:
					gotoxy((x - 1) * 2, y);
					break;
				case RIGHT:
					gotoxy((x + 1) * 2, y);
					break;
				default:
					break;
				}
				std::cout << "  ";
			}
			command = _getch();
			switch (command)
			{
			case UP:
				way = command;
				if (y > 1)
					y--;
				break;
			case DOWN:
				way = command;
				if (y < BoardY - 2)
					y++;
				break;
			case LEFT:
				way = command;
				if (x > 1)
					x--;
				break;
			case RIGHT:
				way = command;
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
				if(!attack)
					attack = true;
				break;
			case ESCAPE:		// �ڷΰ��� or ���α׷� ����
				key = command;
				break;
			default:
				break;
			}
		}
	}
	if (attack_count > 3)
	{
		if (attack) {
			switch (way) {
			case UP:
				gotoxy(x * 2, y - 1);
				break;
			case DOWN:
				gotoxy(x * 2, y + 1);
				break;
			case LEFT:
				gotoxy((x - 1) * 2, y);
				break;
			case RIGHT:
				gotoxy((x + 1) * 2, y);
				break;
			default:
				break;
			}
			std::cout << "  ";
		}
		attack_count = 0;
		attack = false;
	}
}

void Player::Render()
{

	gotoxy(x * 2, y);
	std::cout << "��";
	if (attack) {
		switch (way) {
		case UP:
			gotoxy(x * 2, y - 1);
			break;
		case DOWN:
			gotoxy(x * 2, y + 1);
			break;
		case LEFT:
			gotoxy((x - 1) * 2, y);
			break;
		case RIGHT:
			gotoxy((x + 1) * 2, y);
			break;
		default:
			break;
		}
		std::cout << "��";
		attack_count++;
	}
	gotoxy(0, BoardY);
}

void Player::Destroy()
{

}
