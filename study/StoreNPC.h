#pragma once
#include "NPC.h"
class StoreNPC : public NPC
{
public:
    StoreNPC();
    ~StoreNPC();
    virtual void Init();
    virtual void Update();
    virtual void Render();
    virtual void Destroy();
    static unsigned int market_open;
private:
    int arrow = 0;
};

