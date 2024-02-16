#pragma once
#include "Monster.h"
#include "Skill.h"
class Ghost : public Monster
{
public:
	Ghost();
	~Ghost();

	virtual void Init(int inid) final;
	virtual void Update() final;
	virtual void Render() final;
	virtual void Destroy() final;

private:
};

