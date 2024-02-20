#include "Item.h"

Item::Item()
{

}

Item::~Item()
{

}

void Item::Init()
{
	
}

void Item::Update()
{

}

void Item::Render()
{

}

void Item::Destroy()
{

}

void Item::Get_Name(std::string a)
{
	item_name = a;
}

void Item::Get_Price(int a)
{
	item_price = a;
}

void Item::Get_Ability(int a)
{
	item_ability = a;
}

std::string Item::Set_Name()
{
	return item_name;
}
