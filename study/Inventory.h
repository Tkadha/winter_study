#pragma once
#include <utility>
#include <string>
#include "Common.h"
#include "Data.h"

class Inventory
{
public:
	~Inventory();
	Inventory();
	void Init();
	void Update();
	void Render();
	void Clear_Render();
	void In_Item(Item*);
	void Out_Item(int a);
	int Get_Item_Price(int a);
	int Max_Storage();
	Item* Get_Item_Data(int a);
private:
	std::vector<std::pair<Item*, int>> storage;	// 아이템 정보, 갯수
};

