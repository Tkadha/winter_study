#include "Object.h"

Object::Object() : id{ 0 }, pos{ 0,0 }, gold{ 0 }, exp{ 0 }, invincibility{ false }, invincibility_time{ 0 }
,power{1}
{
}

Object::~Object()
{
}

Pos Object::Getpos()
{
	return pos;
}

int Object::Getpower()
{
	return power;
}

void Object::Get_Gold(int g)
{
	gold += g;

}

void Object::Get_Exp(int e)
{
	exp += e;
}

