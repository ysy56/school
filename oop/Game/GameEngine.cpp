#include "GameEngine.h"
#include "Monster.h"
#include "Slime.h"
#include "Orc.h"

void GameEngine::Run(){
    Slime* s = new Slime();
    Orc* o = new Orc();
    int *array = new int[10];
    int frame = 0;
    int num_enemy = 0;
    int score = 0;
    int player_hp = 20;
    int g_Orc = 5;
    int g_Slime = 3;
    bool enemy = true;
    
    cout<<"Hello, Welcome to My Game!"<<endl;
    cout<<"Play to Game!"<<endl;
    cout<<"--------------------------"<<endl;
    while(1){
	frame++;
	
	    if(GenerateEnemy(num_enemy, frame, s, g_Slime))
		array[num_enemy-1]=3;
	    if(GenerateEnemy(num_enemy, frame, o, g_Orc))
		array[num_enemy-1]=5;
	
	if(num_enemy>0){
	    for(int i = 0; i<num_enemy; i++){
		if(array[i] == 3)
		    MoveEnemy(g_Slime, s, player_hp);
		if(array[i] == 5)
		    MoveEnemy(g_Orc, o, player_hp);
	    }
	    GetUserInput(num_enemy, score, enemy);
	}
	Draw(num_enemy, score, player_hp);
	if(player_hp <= 0||num_enemy>=10){
	    cout<<"Game Over"<<endl;
	    break;
	}
	else if(score >= 3){
	    cout<<"축하합니다."<<endl;
	    break;
	}
    }
}

bool GameEngine::GenerateEnemy(int &num_enemy, int &frame, Monster *m, int &g){
    if(frame%g == 0){
	m->Apear();
	num_enemy++;
	return true;
    }
    return false;
}

void GameEngine::MoveEnemy(int &attack, Monster *m, int &player_hp){
    m->Move();
    player_hp = player_hp - attack;
}

void GameEngine::GetUserInput(int &num_enemy, int &score, bool &enemy){
    cout<<"1. 싸운다. 2. 도망간다."<<endl;
    cout<<"입력: ";
    string str;
    cin >> str;
    if(str == "1"){
	cout<<"몬스터와 싸웁니다."<<endl;
	num_enemy--;
	score++;
    }
    else if(str == "2"){
	cout<<"도망갑니다."<<endl;
    }
    if(num_enemy <= 0)
	enemy = false;
}

void GameEngine::Draw(int &num_enemy, int &score, int &player_hp){
    if (player_hp<0)
	player_hp = 0;
    cout<<"----------현재정보----------"<<endl;
    cout<<"현재 몬스터 수:"<<num_enemy<<endl;
    cout<<"현재 점수:"<<score<<endl;
    cout<<"현재 Player HP:"<<player_hp<<endl;
    cout<<"----------------------------"<<endl;
}

