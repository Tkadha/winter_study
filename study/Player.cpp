#include "Player.h"
#include "Input.h"

Player* Player::instance = nullptr;
bool Player::attack = false;
Pos Player::attackpoint;
Player::Player() : level{1},exp{0},hp{10},mp{10},gold{0},power{1}, way{ UP }, see_attack(false), attack_count{ 0 }
{
	pos.x = 1;
	pos.y = 1;
	
}

Player::Player(const Player& other) : level{ 1 }, exp{ 0 }, hp{ 10 }, mp{ 10 }, gold{ 0 }, power{ 1 }, way{ UP }, see_attack(false), attack_count{ 0 }
{
	
}

Player* Player::GetInstance()
{
	if (instance == NULL)
		instance = new Player();
	return instance;
}

Player::~Player()
{

}



void Player::Init(int inid) {
	id = inid;
}

void Player::Update() {
	if (Input::input) {
		gotoxy(pos.x * 2, pos.y);
		std::cout << "  ";
		switch (Input::key)
		{
		case UP:
			way = Input::key;
			if (pos.y > 1)
				pos.y--;
			break;
		case DOWN:
			way = Input::key;
			if (pos.y < BoardY - 2)
				pos.y++;
			break;
		case LEFT:
			way = Input::key;
			if (pos.x > 1)
				pos.x--;
			break;
		case RIGHT:
			way = Input::key;
			if (pos.x < BoardX - 2)
				pos.x++;
			break;
		case SPACE:		// 상호작용/확인
			break;
		case D:			// 공격
			if (!attack)
				attack = true;
			break;
		default:
			break;
		}
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
				attackpoint = { pos.x - 1,pos.y };
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
	}
	if (attack_count > 2)
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
			if (pos.y != 1) {
				gotoxy(pos.x * 2, pos.y - 1);
				see_attack = true;
			}
			break;
		case DOWN:
			if (pos.y != BoardY - 2) {
				gotoxy(pos.x * 2, pos.y + 1);
				see_attack = true;
			}
			break;
		case LEFT:
			if (pos.x != 1) {
				gotoxy((pos.x - 1) * 2, pos.y);
				see_attack = true;
			}
			break;
		case RIGHT:
			if (pos.x != BoardX - 2) {
				gotoxy((pos.x + 1) * 2, pos.y);
				see_attack = true;
			}
			break;
		default:
			break;
		}
		if (see_attack) {
			switch (attack_count) {
			case 0:
				std::cout << "◐";
				break;
			case 1:
				std::cout << "●";
				break;
			case 2:
				std::cout << "◑";
				break;
			default:
				break;
			}
		}
		attack_count++;
	}
	State_Render();
	gotoxy(0, BoardY);
}

void Player::Destroy()
{

}

int Player::Getid()
{
	return id;
}

void Player::State_Render()
{
	gotoxy(0, BoardY + 2);
	std::cout << "LEVEL: " << level << '\n';
	std::cout << "EXP: " << exp << '\n';
	std::cout << "HP: " << hp << " MP: " << mp <<'\n';
	std::cout << "GOLD: " << gold << '\n';
}

