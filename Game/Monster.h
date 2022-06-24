#ifndef __MONSTER_H__
#define __MONSTER_H__
#include <iostream>

using namespace std;

class Monster{
    public:	
	virtual void Move() = 0;
	virtual void Apear() = 0;
};

#endif
