#pragma once
#include "NPC.h"
class QuestNPC :
    public NPC
{
public:
    QuestNPC();
    ~QuestNPC();
    virtual void Init();
    virtual void Update();
    virtual void Render();
    virtual void Destroy();
    static unsigned int open;
};

