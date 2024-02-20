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
		gotoxy(BoardX + 25, BoardY + 2);
		std::cout << "�κ��丮�� ����ֽ��ϴ�.";
	}
	for (int i = 0; i < storage.size(); ++i) {
		if (i >= 10) gotoxy(BoardX + 50, BoardY + 2 + (10 - i));
		else gotoxy(BoardX + 25, BoardY + 2 + i);
		std::cout << storage[i].first->Set_Name() << " ����: " << storage[i].second;
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
