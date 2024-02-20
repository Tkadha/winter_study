#include "Market.h"

Market::Market()
{
}

Market::~Market()
{
}

void Market::Init()
{

}

void Market::Update()
{
	if (Input::input) {
		if (Input::key == PLUS) {
			gotoxy(BoardX * 10 / 3, 5 + arrow);
			std::cout << "   ";
			gotoxy(BoardX * 6 / 3, 5 + arrow);
			std::cout << "   ";
			arrow++;
		}
		else if (Input::key == MINUS) {
			if (arrow > 0) {
				gotoxy(BoardX * 10 / 3, 5 + arrow);
				std::cout << "   ";
				gotoxy(BoardX * 6 / 3, 5 + arrow);
				std::cout << "   ";
				arrow--;
			}
		}
		else if (Input::key == B) {
			if (market_state == 1) {
				gotoxy(BoardX * 7 / 2, 5 + Data::items.size() + 3);
				cout << "                ";
				temp_price = Data::items[arrow]->Get_Price();
				player_gold = p->Getgold();
				if (player_gold < temp_price) {
					gotoxy(BoardX * 7 / 2, 5 + Data::items.size() + 3);
					cout << "돈이 부족합니다.";
				}
				else {
					buy_item = Data::items[arrow];
					p->Setgold(-temp_price);
					p->inven.In_Item(buy_item);
				}
			}
			else if (market_state == 2) {
				p->Setgold(p->inven.Get_Item_Price(arrow));
				p->inven.Out_Item(arrow);
				for (int i = 0; i < Data::items.size(); i++) {
					gotoxy(BoardX * 7 / 3, 5 + i);
					cout << "                                ";
				}
				gotoxy(BoardX * 6 / 3, 5 + arrow);
				cout << "  ";
				arrow = 0;
			}
		}
	}
}

void Market::Render()
{
	if (first == 1) {
		first = 0;
		arrow = 0;
	}
	market_state = 1;
	for (int i = 0; i < Data::items.size(); i++) {
		gotoxy(BoardX * 7 / 2, 5+i);
		temp_name = Data::items[i]->Get_Name();
		temp_price = Data::items[i]->Get_Price();
		cout << temp_name;
		cout << "        ";
		cout << temp_price;
		
	}
	gotoxy(BoardX * 10 / 3, 5 + arrow);
	std::cout << "->";
}

void Market::RenderSell()
{
	
	market_state = 2;
	gotoxy(BoardX * 10 / 3, 5 + arrow);
	std::cout << "  ";
	if (first == 0) {
		first = 1;
		arrow = 0;
	}
	gotoxy(BoardX * 6 / 3, 5 + arrow);
	std::cout << "->";
	for (int i = 0; i < Data::items.size(); i++) {
		gotoxy(BoardX * 7 / 2, 5 + i);
		std::cout << ""                       "";
	}

	p->inven.Render();
}

void Market::Destroy()
{
}
