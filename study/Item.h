#pragma once
#include <string>
#include <fstream>


enum Item_Code{
	Hp_low_potion,
	Hp_middle_potion,
	Hp_high_potion,

	Mp_low_potion,
	Mp_middle_potion,
	Mp_high_potion,

	Sword,
	Spear,
	Axe,

	Lether_Helmet,
	Lether_Chestplate,
	Lether_leggings,
	Lether_shoes,

	Iron_Helmet,
	Iron_Chestplate,
	Iron_leggings,
	Iron_shoes,

	Diamond_Helmet,
	Diamond_Chestplate,
	Diamond_leggings,
	Diamond_shoes,

	Goblin_ear,
	Ghost_soul
};





class Item
{
public:
	Item();
	~Item();
	void Init();
	void Update();
	void Render();
	void Destroy();
	
	bool operator==(Item& other) const {
		return (id == other.id);
	}
	void Set_Name(std::string a);
	void Set_Price(int a);
	void Set_Ability(int a);
	std::string Get_Name();
	int Get_Price();
	int Get_Ability();
private:
	Item_Code id;
	std::string item_name;
	int item_price;
	int item_ability;
	
};

