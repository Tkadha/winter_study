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

void Item::Set_Name(std::string a)
{
	item_name = a;
}

void Item::Set_Price(int a)
{
	item_price = a;
}

void Item::Set_Ability(int a)
{
	item_ability = a;
}

void Item::Set_id(int a)
{
	id = a;
}

std::string Item::Get_Name()
{
	return item_name;
}

int Item::Get_Price()
{
	return item_price;
}

int Item::Get_Ability()
{
	return item_ability;
}

int Item::Get_Code()
{
	return id;
}
