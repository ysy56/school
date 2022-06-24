#ifndef __SLIME_H__
#define __SLIME_H__
#include "Monster.h"
#include <iostream>
using namespace std;

class Slime:public Monster{
    public:
	virtual void move();
};

#endif
