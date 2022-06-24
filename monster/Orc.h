#ifndef __ORC_H__
#define __ORC_H__
#include "Monster.h"
#include <iostream>
using namespace std;

class Orc:public Monster{
    public:
	virtual void move();
};

#endif
