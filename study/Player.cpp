#include "Player.h"
#include "Input.h"

Player* Player::instance = nullptr;
bool Player::attack = false;
bool Player::skill_on = false;
Pos Player::attackpoint;

Player::Player() : level{ 1 }, hp{ 10 }, mp{ 10 }, way{ UP }, max_hp{ 10 }, max_mp{ 10 },
see_attack{ false }, attack_count{ 0 }, skill_count{ 0 }
{
	pos.x = 1;
	pos.y = 1;
	exp = 1000;
	gold = 100;
	skill.Set_Center(pos);
	hp_level = 0;
	mp_level = 0;
	range_level = 0;
	power_level = 0;
}

Player::Player(const Player& other) : level{ 1 }, hp{ 10 }, mp{ 10 }, way{ UP }, max_hp{ 10 }, max_mp{ 10 },
see_attack{ false }, attack_count{ 0 }, skill_count{ 0 }
{
	pos.x = 1;
	pos.y = 1;
	exp = 1000;
	gold = 100;
	skill.Set_Center(pos);
	hp_level = 0;
	mp_level = 0;
	range_level = 0;
	power_level = 0;
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
	Regen_State();

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
		case SPACE:		

			break;
		case D:			// 공격
			if (skill_on) break;
			if (!attack)
				attack = true;
			break;
		case S:			// 스킬 공격
			if (attack) break;
			if (!skill_on) {
				if (mp < 2) break;
				skill_on = true;
				mp -= 2;
			}
			break;
		case O:
			gotoxy(pos.x * 2, pos.y);
			std::cout << "▣";
			Upgrade_State();
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
		skill.Set_Center(pos);
		skill.Set_Hit_Box();
		++skill_count;
	}
	if (skill_count > 2) {
		skill_on = false;
		skill_count = 0;
		skill.Erase_Render();
	}
	if (invincibility) {
		++invincibility_time;
		if (invincibility_time > 30) {
			invincibility_time = 0;
			invincibility = false;
		}
		return;
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
int Player::Getgold()
{
	return gold;
}

void Player::Setexp(int a)
{
	exp += a;
}

void Player::Setgold(int b) 
{
	gold += b;
}

void Player::Set_Hp(int h)
{
	if (invincibility) return;
	hp -= h;
	invincibility = true;
	if (hp < 0) hp = 0;
}

int Player::Get_Power()
{
	return power;
}

int Player::Get_Level()
{
	return level;
}

void Player::State_Render()
{
	gotoxy(0, BoardY + 2);
	std::cout << "LEVEL: " << level << "    " << '\n';
	std::cout << "EXP: " << exp << "    " << '\n';
	std::cout << "HP: " << hp << "/" << max_hp << " MP: " << mp << "/" << max_mp << "    " << '\n';
	std::cout << "POWER: " << power << "    " << '\n';
	std::cout << "GOLD: " << gold << "    " << '\n';
}

Skill Player::Get_Skill()
{
	return skill;
}

void Player::Regen_State()
{
	static int regen_count;
	++regen_count;
	if (regen_count > 30) {
		if (hp < max_hp)++hp;
		if (mp < max_mp)++mp;
		regen_count = 0;
	}
}

void Player::Upgrade_State()
{
	int command = 0;
	int key = 0;
	while (key != ESCAPE) {
		command = _getch();
		switch (command)
		{
		case ESCAPE:		//프로그램 종료
			key = command;
			break;
		case NUM_1:			// 체력 업
			if (exp > (hp_level + 1) * (20 + hp_level * 10)) {
				exp -= (hp_level + 1) * (20 + hp_level * 10);
				++hp_level;
				max_hp = 10 + hp_level * 10;
			}
			else {
				gotoxy(0, BoardY + 7);
				std::cout << (hp_level + 1) * (20 + hp_level * 10) - exp<< " 경험치가 부족합니다.";
			}
			break;
		case NUM_2:			// 마나 업
			if (exp > (mp_level + 1) * (20 + mp_level * 10)) {
				exp -= (mp_level + 1) * (20 + mp_level * 10);
				++mp_level;
				max_mp = 10 + mp_level * 10;
			}
			else {
				gotoxy(0, BoardY + 7);
				std::cout << (mp_level + 1) * (20 + mp_level * 10) - exp << " 경험치가 부족합니다.";
			}
			break;
		case NUM_3:			// 사거리 업
			if (exp > (range_level + 1) * (500 + range_level * 300))
			{
				exp -= (range_level + 1) * (500 + range_level * 300);
				++range_level;
				skill.Upgrade_Range();
			}
			else {
				gotoxy(0, BoardY + 7);
				std::cout << (range_level + 1) * (500 + range_level * 300) - exp << " 경험치가 부족합니다.";
			}
			break;
		case NUM_4:
			if (exp > (power_level + 1) * (200 + power_level * 100))
			{
				exp -= (power_level + 1) * (200 + power_level * 100);
				++power_level;
				++power;
			}
			else {
				gotoxy(0, BoardY + 7);
				std::cout << (power_level + 1) * (200 + power_level * 100) - exp << " 경험치가 부족합니다.";
			}
			break;
		default:
			key = command;
			break;
		}
		level = 1 + (hp_level + mp_level + power_level) / 3;
		State_Render();
	}
	gotoxy(0, BoardY + 7);
	std::cout <<"                               ";
}
