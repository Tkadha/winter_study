#pragma once
#include "Object.h"
class NPC :
    public Object
{
    // Object��(��) ���� ��ӵ�
    void Init(int inid) override;
    void Update() override;
    void Render() override;
    void Destroy() override;
    int Getid() override;

    char shape;
    int state;

};

