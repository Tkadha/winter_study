#include "Inventory.h"

Inventory::~Inventory()
{
}

Inventory::Inventory()
{
}

void Inventory::Init()
{
}

void Inventory::Update()
{
}

void Inventory::Render()
{
	if (storage.empty()) {
		gotoxy(BoardX * 7 / 3, 5);
		std::cout << "인벤토리가 비어있습니다.";
	}
	for (int i = 0; i < storage.size(); ++i) {
		
		gotoxy(BoardX * 7 / 3, 5+i);
		std::cout << storage[i].first->Get_Name() << " 갯수: " << storage[i].second<< "   ";
	}
}

void Inventory::Clear_Render()
{
	if (storage.empty()) {
		gotoxy(BoardX * 7 / 3, 5);
		std::cout << "                     ";
	}
	for (int i = 0; i < storage.size()+1; ++i) {

		gotoxy(BoardX * 7 / 3, 5 + i);
		std::cout <<"                                ";
	}
}

void Inventory::In_Item(Item* item)
{
	for (int i = 0; i < storage.size(); ++i) {
		if (storage[i].first == item) {
			++storage[i].second;
			return;
		}
	}
	storage.emplace_back(std::make_pair(item, 1));
}

void Inventory::Out_Item(int a)
{
	if (storage[a].second > 1) --storage[a].second;
	else storage.erase(storage.begin() + a);
}

int Inventory::Get_Item_Price(int a)
{
	return storage[a].first->Get_Price();
}

int Inventory::Max_Storage()
{
	return storage.size();
}

Item* Inventory::Get_Item_Data(int a)
{
	return storage[a].first;
}
