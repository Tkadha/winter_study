#pragma once
#include "Common.h"
class Object
{
public:
	Object();
	Object(Pos p, int inid);
	~Object();
public:
	virtual void Init(int inid) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Destroy() = 0;
	virtual int Getid() = 0;
	virtual Pos Getpos();
private:

protected:
	int id;
	Pos pos;
};



