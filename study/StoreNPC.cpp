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
				for (int i = 0; i < Data::items.size(); i++) {
					gotoxy(BoardX * 7 / 2, 5 + i);
					std::cout << "                             ";
				}
				market_open = 2;
			}
			else {
				for (int i = 0; i < Data::items.size(); i++) {
					gotoxy(BoardX * 7 / 3, 5 + i);
					std::cout << "                             ";
				}
				gotoxy((BoardX * 7 / 3) - 3, 5 + arrow);
				std::cout << "  ";
				gotoxy(BoardX * 10 / 3 - 5, 3);
				std::cout << "      ";
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
