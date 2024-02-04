#pragma once
#include "Object.h"
#include "Common.h"
#include "Input.h"
#include <random>
//using namespace std;
class NPC :
    public Object
{
public:
    NPC();
    ~NPC();
    // Object을(를) 통해 상속됨
    void Init(int inid) override;
    void Update() override;
    void Render() override;
    void Destroy() override;
    int Getid() override;
protected:
    char shape;
    int state;

};

