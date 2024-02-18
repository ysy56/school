#include "GameEngine.h"
#include "linux_kbhit.h"
#define MAIN_X 40
#define MAIN_Y 30

GameEngine::GameEngine(){
    loop = true;
    p = new Player();
}

void GameEngine::Run(){
    int frame = 0;
    while (loop){
	frame++;
	GetUserInput();
	//GenerateEnemy();
	//MoveEnemy();
	Draw();
    }
}

void GameEngine::GetUserInput(){
    init_keyboard();
    while(1){
	if(_kbhit()){

	    int ch = _getch();
	    switch(ch){				
		case 'a':
		    cout<<"left"<<endl;
		    p->Move(-1, 0);
		    break;
		case 'd':
		    cout<<"right"<<endl;
		    p->Move(1, 0);
		    break;
		case 's':
		    cout<<"down"<<endl;
		    p->Move(0, 1);
		    break;
		case 'w': 
		    cout<<"up"<<endl;
		    p->Move(0, -1);
		    break;
	    }
	}
    }
    close_keyboard();
}

void GameEngine::Draw(){
    
}
