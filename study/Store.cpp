#include "Store.h"
#include "Input.h"
Store::Store()
{
}

Store::~Store()
{
}

void Store::Init()
{
}

void Store::Update()
{
	
}

void Store::Render()
{
	gotoxy(BoardX * 7 / 3, 10);
	std::cout << "하급 체력 포션  50G";
	gotoxy(BoardX * 7 / 3, 11);
	std::cout << "중급 체력 포션  100G";
	gotoxy(BoardX * 7 / 3, 12);
	std::cout << "상급 체력 포션  200G";
}

void Store::RenderSell()
{
	gotoxy(BoardX * 7 / 3, 10);
	std::cout << "판매화면입니다.";
}

void Store::Destroy()
{
}
