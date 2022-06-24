#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>

using namespace std;

class Player{
    private:
	int x_;
	int y_;
    public:
	Player();
	void Move(int x, int y);
};

#endif
