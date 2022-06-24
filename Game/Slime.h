#ifndef __SLIME_H__
#define __SLIME_H__
#include <iostream>
#include "Monster.h"
using namespace std;

class Slime:public Monster{
    public:
	virtual void Move();
	virtual void Apear();
};

#endif
