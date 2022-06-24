#ifndef __MONSTER_H__
#define __MONSTER_H__
#include <iostream>
using namespace std;

class Monster{
    private:
	Monster *next;
    public:
	Monster(){next = NULL;}
	virtual void move();
	Monster* add(Monster *m);
	Monster* getNext(){return next;}
};

#endif
