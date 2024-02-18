#include <iostream>
#include "Game.h"
#include "GameEngine.h"
using namespace std;

int main(int argc, char* argv[]){
    Game* game = new Game();
    game->Run();
}
