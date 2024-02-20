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
	void In_Item(Item*);
	
private:
	std::vector<std::pair<Item*, int>> storage;	// 아이템 정보, 갯수
};

