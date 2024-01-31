#pragma once
#include "Common.h"
class Object
{
public:
	Object();
	~Object();
public:
	virtual void Init(int inid) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
	virtual int Getid() = 0;
	virtual Pos Getpos();
	virtual void Get_Gold(int);
	virtual void Get_Exp(int);
private:

protected:
	int exp;
	int gold;
	int id;
	Pos pos;
};



