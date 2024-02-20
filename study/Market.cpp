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
			arrow++;
		}
		else if (Input::key == MINUS) {
			if (arrow > 0) {
				gotoxy(BoardX * 10 / 3, 5 + arrow);
				std::cout << "   ";
				arrow--;
			}
		}
		else if (Input::key == B) {
			gotoxy(BoardX * 7 / 2, 5 + Data::items.size() + 3);
			cout << "                ";
			temp_price = Data::items[arrow]->Get_Price();
			player_gold = p->Getgold();
			if(player_gold<temp_price){
				gotoxy(BoardX * 7 / 2, 5 + Data::items.size()+3);
				cout << "not enough money";
			}
			else {
				p->Setgold(-temp_price);
			}
		}
	}
}

void Market::Render()
{
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

}

void Market::Destroy()
{
}
