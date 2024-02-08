#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}


void Board::init()
{
	gotoxy(0, BoardY + 10);
	std::cout << "O = Goblin";
	gotoxy(0, BoardY + 11);
	std::cout << "G = Ghost";
}

void Board::Update()
{
}

void Board::Render()
{
	for (int i = 0; i < BoardY; ++i) {
		for (int j = 0; j < BoardX; ++j) {
			if (i == 0 || j == 0 || i == BoardY - 1 || j == BoardX - 1) {
				gotoxy(j*2, i);
				std::cout << "бс";
			}
		}
		std::cout << std::endl;
	}
}

void Board::Destroy()
{
}
