#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}


void Board::init()
{
	/*gotoxy(0, 0);
	for (int i = 0; i < BoardY; ++i) {
		for (int j = 0; j < BoardX; ++j) {
			if (i == 0 || j == 0 || i == BoardY - 1 || j == BoardX - 1) {
				std::cout << "бс";
			}
			else
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}*/
}

void Board::Update()
{
}

void Board::Render()
{
	/*gotoxy(0, BoardY+1);
	for (int i = 0; i < BoardY; ++i) {
		for (int j = 0; j < BoardX; ++j) {
			std::cout << board[i][j]<<' ';
		}
		std::cout << std::endl;
	}*/
	gotoxy(0, 0);
	for (int i = 0; i < BoardY; ++i) {
		for (int j = 0; j < BoardX; ++j) {
			if (i == 0 || j == 0 || i == BoardY - 1 || j == BoardX - 1) {
				std::cout << "бс";
			}
			else
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void Board::Destroy()
{
}
