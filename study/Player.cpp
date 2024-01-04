#include "Player.h"



Player::Player()
{
	x = 1;
	y = 1;
	key = 0;
	way = UP;
	attack = false;
	see_attack = false;
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
			case SPACE:		// 상호작용/확인

				break;
			case D:			// 공격
				if(!attack)
					attack = true;
				break;
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
			if (see_attack)
				std::cout << "  ";
		}
		attack_count = 0;
		attack = false;
	}
}

void Player::Render()
{

	gotoxy(x * 2, y);
	std::cout << "▣";
	if (attack) {
		see_attack = false;
		switch (way) {
		case UP:
			gotoxy(x * 2, y - 1);
			if (y != 1) {
				std::cout << "◆";
				see_attack = true;
			}

			break;
		case DOWN:
			gotoxy(x * 2, y + 1);
			if (y != BoardY - 2) {
				std::cout << "◆";
				see_attack = true;
			}
			break;
		case LEFT:
			gotoxy((x - 1) * 2, y);
			if (x != 1) {
				std::cout << "◆";
				see_attack = true;
			}
			break;
		case RIGHT:
			gotoxy((x + 1) * 2, y);
			if (x != BoardX - 2) {
				std::cout << "◆";
				see_attack = true;
			}
			break;
		default:
			break;
		}
		attack_count++;
	}
	gotoxy(0, BoardY);
}

void Player::Destroy()
{

}

