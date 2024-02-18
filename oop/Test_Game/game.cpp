#include "Game.h"

Game::Game(){
    gEngine = new GameEngine();    
}

void Game::Run(){
    gEngine->Run();
}

void Game::ClearDisplay(){
    write(1, "\033[1;1H\033[2J", 10);
}
