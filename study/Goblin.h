#pragma once
#include "Monster.h"
class Goblin : public Monster
{
public:
	Goblin();
	~Goblin();

	virtual void Init(int inid) final;
	virtual void Update() final;
	virtual void Render() final;
	virtual void Destroy() final;

	
};

