#include "StoreNPC.h"
unsigned int StoreNPC::market_open = 0;
StoreNPC::StoreNPC()
{

}

StoreNPC::~StoreNPC()
{

}

void StoreNPC::Init()
{

}

void StoreNPC::Update()
{
	if (Input::input) {
		if (Input::key == M) {
			if (market_open == 0) {
				market_open = 1;
			}
			else if (market_open == 1) {
				gotoxy(BoardX * 7 / 3, 10);
				std::cout << "                                          ";
				gotoxy(BoardX * 7 / 3, 11);
				std::cout << "                                          ";
				gotoxy(BoardX * 7 / 3, 12);
				std::cout << "                                          ";
				market_open = 2;
			}
			else {
				gotoxy(BoardX * 7 / 3, 10);
				std::cout << "                                          ";
				gotoxy(BoardX * 7 / 3, 11);
				std::cout << "                                          ";
				gotoxy(BoardX * 7 / 3, 12);
				std::cout << "                                          ";
				market_open = 0;
			}
		}
	}
}

void StoreNPC::Render()
{

}

void StoreNPC::Destroy()
{

}
