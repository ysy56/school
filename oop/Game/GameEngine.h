#ifndef __GAMEENGINE_H__
#define __GAMEENGINE_H__
#include <iostream>
#include <stdbool.h>
#include "Monster.h"
#include "Slime.h"

using namespace std;

class GameEngine{
    private:
	bool GenerateEnemy(int &num_enemy, int &frame, Monster *m, int &g);
	void MoveEnemy(int &attack, Monster *m, int &player_hp);
	void GetUserInput(int &num_enemy, int &score, bool &enemy);
	void Draw(int &num_enemy, int &score, int &player_hp);
    public:
	GameEngine();
	void Run();
};

#endif
