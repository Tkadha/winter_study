#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>

const int BoardX = 30;
const int BoardY = 30;

const int  UP = 72;
const int  DOWN = 80;
const int  LEFT = 75;
const int  RIGHT = 77;
const int  SPACE = 32;
const int  D = 100;
const int  ESCAPE = 27;
const int  ENTER = 13;
const int  WAVE = 96;

struct Pos {
	int x;
	int y;
};

void gotoxy(int x, int y);

enum State {
	State_Player= 0,
	State_Monster = 10000,
};



