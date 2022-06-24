#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__
#include <iostream>
#include "Player.h"

using namespace std;

class GameEngine{
    private:
	Player *p;
	bool loop;	
	void GetUserInput();
    public:
	GameEngine();
	void Run();
};

#endif
