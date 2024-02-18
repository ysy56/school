#include <iostream>
#vector
using namespace std;

enum DIRECTION{LEFT, RIGHT, UP, DOWN};

class ScreenEntity{
    int x;
    int y;
    char *image;
    public:
    void Draw(){}
};

class Character : public ScreenEntity {
    int hp;
    int mp;
    string name;
    public:
    void move(){ };
};

class Player : public Character{
    void move(enum DIRECTION dir){
	switch(dir){
	    case LEFT:
		break;
	    case RIGHT:
		break;
	    case UP:
		break;
	    case DOWN:
		break;
	}
    };
};

class Enemy : public Character{
    void move(){ };
};

class Slime : public Enemy{
    public:
	void move(){
	    x = x+2;       
	};

};

class Orc : public Enemy{
    public:
	void move(){
	    x = x+1;
	    y = y+1;
	};
};

class Stone : public Enemy{
    public:
	void move(){ };
};

class GameEngine{
    private:
	bool loopflag;
	void CheckUserInput(){}
	void Draw();
    public:
	GameEngine(){loopflag = true;}
	vector<Character*> character_vec;

	void run(){
	    Orc *orc = new Orc();
	    Slime *slime = new Slime();
	    Player *player = new Player();
	    Stone *stone = new Stone();

	    character_vec.push(orc);
	    character_vec.push(slime);
	    character_vec.push(player);
	    character_vec.push(slime);

	    while(loopflag){
		enum DIRECRION dir = CheckUserInput();

		for(int i = 0; i<character_vec.size(); i++)
		    character_vec[i].move();
	
		for(int i = 0; i<character_vec.size(); i++)
		    character_vec[i].Draw();	
		orc->move();
		slime->move();
		stone->move();
		player->move(dir);
		
		orc->Draw();
		slime->Draw();
		stone->Draw();
		player->Draw();
	    }
	}
};

class Game{
    private:
	GameEngine *gEngine;

    public:
	Game(){
	    gEngine = new GameEngine();
	}
	void run(){
	    gEngine->run();
	}
};

int main(int argc, char* argv[]){
    Game* game = new Game();
    game->run();
}
