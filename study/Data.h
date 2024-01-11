#pragma once
#include "Common.h"
#include "Object.h"
class Data
{
public:
	Data();
	~Data();
	static std::vector<Object* > objects;

	static unsigned int user_id;
	static unsigned int global_id;

private:

};
