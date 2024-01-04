#include "Common.h"
#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::init()
{
	for (int i = 0; i < BoardY; ++i) {
		for (int j = 0; j < BoardX; ++j) {
			if (i == 0 || j == 0 || i == BoardY - 1 || j == BoardX - 1) {
				std::cout << "бс";
			}
			else
				std::cout << "  ";
		}
		std::cout << std::endl;
	}
}

void Board::Update()

{
}

void Board::Render()
{
	
}

void Board::Destroy()
{
}
