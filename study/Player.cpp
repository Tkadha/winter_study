#include "Player.h"
#include "Input.h"



Player::Player()
{
	pos.x = 1;
	pos.y = 1;
	way = UP;
	attack = false;
	see_attack = false;
	attack_count = 0;
}

Player::~Player()
{

}

Pos Player::Getpos()
{
	return pos;
}

int Player::Getkey()
{
	return in.Getkey();
}

bool Player::DoAttack()
{
	return attack;
}

Pos Player::GetAttackPoint()
{
	return attackpoint;
}

void Player::init() {
	in.init();
}

void Player::Update() {
	in.Update();
	if (in.Getinput()) {
		gotoxy(pos.x * 2, pos.y);
		std::cout << "  ";
		command = in.Getcommand();
		if (command == 224) {
			if (attack) {
				switch (way) {
				case UP:
					attackpoint = { pos.x,pos.y - 1 };
					gotoxy(attackpoint.x * 2, attackpoint.y);
					break;
				case DOWN:
					attackpoint = { pos.x,pos.y + 1 };
					gotoxy(attackpoint.x * 2, attackpoint.y);
					break;
				case LEFT:
					attackpoint = { pos.x - 1,pos.y};
					gotoxy(attackpoint.x * 2, attackpoint.y);
					break;
				case RIGHT:
					attackpoint = { pos.x + 1,pos.y };
					gotoxy(attackpoint.x * 2, attackpoint.y);
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
				if (pos.y > 1)
					pos.y--;
				break;
			case DOWN:
				way = command;
				if (pos.y < BoardY - 2)
					pos.y++;
				break;
			case LEFT:
				way = command;
				if (pos.x > 1)
					pos.x--;
				break;
			case RIGHT:
				way = command;
				if (pos.x < BoardX - 2)
					pos.x++;
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
				gotoxy(pos.x * 2, pos.y - 1);
				break;
			case DOWN:
				gotoxy(pos.x * 2, pos.y + 1);
				break;
			case LEFT:
				gotoxy((pos.x - 1) * 2, pos.y);
				break;
			case RIGHT:
				gotoxy((pos.x + 1) * 2, pos.y);
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

	gotoxy(pos.x * 2, pos.y);
	std::cout << "▣";
	if (attack) {
		see_attack = false;
		switch (way) {
		case UP:
			gotoxy(pos.x * 2, pos.y - 1);
			if (pos.y != 1) {
				std::cout << "◆";
				see_attack = true;
			}

			break;
		case DOWN:
			gotoxy(pos.x * 2, pos.y + 1);
			if (pos.y != BoardY - 2) {
				std::cout << "◆";
				see_attack = true;
			}
			break;
		case LEFT:
			gotoxy((pos.x - 1) * 2, pos.y);
			if (pos.x != 1) {
				std::cout << "◆";
				see_attack = true;
			}
			break;
		case RIGHT:
			gotoxy((pos.x + 1) * 2, pos.y);
			if (pos.x != BoardX - 2) {
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

