#include "Object.h"

Object::Object() : id{ 0 }, pos{ 0,0 }
{
}

Object::Object(Pos p, int inid) : pos{ p } ,id{inid}
{
}

Object::~Object()
{
}

Pos Object::Getpos()
{
	return pos;
}

