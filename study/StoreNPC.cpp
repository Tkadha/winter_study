#include "StoreNPC.h"
unsigned int StoreNPC::market_open = 0;
StoreNPC::StoreNPC()
{
}

StoreNPC::~StoreNPC()
{
}

void StoreNPC::Init()
{
}

void StoreNPC::Update()
{
	if (Input::input) {
		if (Input::key == M) {
			if (market_open == 0) {
				market_open = 1;
			}
			else if (market_open == 1) {
				market_open = 2;
			}
			else {
				market_open = 0;
			}
		}
		
	}
}

void StoreNPC::Render()
{
	
}

void StoreNPC::Destroy()
{
}
