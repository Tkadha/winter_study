#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>

#define BoardX 15
#define BoardY 15

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define D 100
#define ESCAPE 27
#define ENTER 13
#define WAVE 96

struct Pos {
	int x;
	int y;
};

void gotoxy(int x, int y);

enum State {
	State_Wall,
	State_Player,
	State_Player_attack,
	State_Monster,
	State_Empty
};



