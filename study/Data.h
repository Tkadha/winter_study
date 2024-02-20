#pragma once
#include "Common.h"
#include "Object.h"
#include "Item.h"
class Data
{
public:
	Data();
	~Data();

	static std::vector<Object* > objects;
	static std::vector<Item* > items;
	static unsigned int user_id;
	static unsigned int global_id;

private:

};
