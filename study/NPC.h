#pragma once
#include "Object.h"
class NPC :
    public Object
{
    // Object을(를) 통해 상속됨
    void Init(int inid) override;
    void Update() override;
    void Render() override;
    void Destroy() override;
    int Getid() override;

    char shape;
    int state;

};

