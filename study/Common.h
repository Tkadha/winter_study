#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <fstream>

const int BoardX = 30;
const int BoardY = 30;


const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;
const int SPACE = 32;
const int D = 100;
const int ESCAPE = 27;
const int ENTER = 13;
const int WAVE = 96;
const int Q = 113;
const int E = 101;
const int W = 119;
const int P = 112;
const int J = 106;
const int K = 107;
const int S = 115;
const int O = 111;
const int I = 105;
const int NUM_1 = 49;
const int NUM_2 = 50;
const int NUM_3 = 51;
const int NUM_4 = 52;
const int  M = 109;
const int  PLUS = 43;
const int  MINUS = 45;
const int  B = 98;


struct Pos {
	int x;
	int y;

	bool operator==(Pos& other) const {
		return (x == other.x) && (y == other.y);
	}
};

void gotoxy(int x, int y);

enum State {
	State_Player= 0,
	State_Monster = 10000,
};



