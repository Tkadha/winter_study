#include "Player.h"
#include "Input.h"

Player* Player::instance = nullptr;
bool Player::attack = false;
bool Player::skill_on = false;
Pos Player::attackpoint;

Player::Player() : level{ 1 }, hp{ 10 }, mp{ 10 }, power{ 1 }, way{ UP }, 
see_attack{ false }, attack_count{ 0 },skill_count{0}
{
	pos.x = 1;
	pos.y = 1;
	exp = 0;
	gold = 100;
	skill.Set_Center(pos);
}

Player::Player(const Player& other) : level{ 1 }, hp{ 10 }, mp{ 10 }, power{ 1 }, way{ UP }, 
see_attack{ false }, attack_count{ 0 }, skill_count{ 0 }
{
	pos.x = 1;
	pos.y = 1;
	exp = 0;
	gold = 100;
	skill.Set_Center(pos);
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
			if (skill_on) break;
			if (!attack)
				attack = true;
			break;
		case S:			// 스킬 공격
			if (attack) break;
			if (!skill_on)
				skill_on = true;
			break;
		default:
			break;
		}
		if (attack) {
			gotoxy(attackpoint.x * 2, attackpoint.y);
			std::cout << "  ";
			switch (way) {
			case UP:
				attackpoint = { pos.x,pos.y - 1 };
				break;
			case DOWN:
				attackpoint = { pos.x,pos.y + 1 };
				break;
			case LEFT:
				attackpoint = { pos.x - 1,pos.y };
				break;
			case RIGHT:
				attackpoint = { pos.x + 1,pos.y };
				break;
			default:
				break;
			}
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
	if (skill_on) {
		skill.Erase_Render();
		skill.Set_Center(pos);
		skill.Set_Hit_Box();
		++skill_count;
	}
	if (skill_count > 2) {
		skill_on = false;
		skill_count = 0;
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
	if (skill_on) {
		skill.Render();
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

void Player::Setexp(int a)
{
	gold += a;
}

void Player::Setgold(int b) 
{
	exp += b;
}

void Player::State_Render()
{
	gotoxy(0, BoardY + 2);
	std::cout << "LEVEL: " << level << '\n';
	std::cout << "EXP: " << exp << '\n';
	std::cout << "HP: " << hp << " MP: " << mp << '\n';
	std::cout << "GOLD: " << gold << '\n';
}

Skill Player::Get_Skill()
{
	return skill;
}
