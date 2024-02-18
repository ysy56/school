#ifndef __ORC_H__
#define __ORC_H__
#include <iostream>
#include "Monster.h"
using namespace std;

class Orc:public Monster{
    public:
	virtual void Move();
	virtual void Apear();
};

#endif
