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
	std::cout << "�ϱ� ü�� ����  50G";
	gotoxy(BoardX * 7 / 3, 11);
	std::cout << "�߱� ü�� ����  100G";
	gotoxy(BoardX * 7 / 3, 12);
	std::cout << "��� ü�� ����  200G";
}

void Store::RenderSell()
{
	gotoxy(BoardX * 7 / 3, 10);
	std::cout << "�Ǹ�ȭ���Դϴ�.";
}

void Store::Destroy()
{
}
