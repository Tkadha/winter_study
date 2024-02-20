#pragma once
#include "Common.h"
#include "Quest.h"
#include "Object.h"
#include "Item.h"
class Data
{
public:
	Data();
	~Data();

	static std::vector<Object* > objects;
	static std::vector<Item* > items;
	static std::vector<Item* > inventorys;
	static unsigned int user_id;
	static unsigned int global_id;

private:

};
