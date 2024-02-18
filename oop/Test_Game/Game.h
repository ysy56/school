#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include "GameEngine.h"

using namespace std;

class Game{
    private:
	GameEngine *gEngine;
    public:
	Game();
	void Run();
	void ClearDisplay();
};

#endif
