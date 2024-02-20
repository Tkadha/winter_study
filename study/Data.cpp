#include "Data.h"

std::vector<Object*> Data::objects;
std::vector<Item*> Data::items;
unsigned int Data::user_id = 0;
unsigned int Data::global_id = 1;


Data::Data()
{
}

Data::~Data()
{
}