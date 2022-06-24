#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <vector>

using namespace std;


void ClearDisplay() {
  write (1, "\033[1;1H\033[2J", 10);
}


struct MonsterGenerationInfo {
	int frame;
	char name[100];
	int x;
	int y;	
};

class Monster {
	public:
		int x, y;
		virtual void Move() = 0;
		virtual char GetAppearance() = 0;
};

class Mole1 : public Monster{
	int width_;
	int height_;
	public:

		Mole1(int width, int height,int x, int y) {this->x = x; this->y = y;
			width_ = width; height_ = height;}

		char GetAppearance() { return '>';}
		virtual void Move() {
			x = (x + 1) % width_; 
		}	
};

class Mole2 : public Monster{
	int width_;
	int height_;
	public:
		Mole2(int width, int height,int x, int y) {this->x = x; this->y = y;
			width_ = width; height_ = height;}

		char GetAppearance() { return 'V';}
		virtual void Move() {
				y = (y + 1) % height_;
		}	
};

class Map {
	private:
		int width;
		int height;
		char map[20][20];
	public:
		Map(int width, int height) { this->width = width; this->height=height; }
		void ClearMapArray() {
			for(int y = 0 ; y < height ; y++) 
				for(int x = 0 ; x < width ; x++)
					map[y][x] = ' ';	
		}

		void UpdateMapArray(vector<Monster*> monsters_vec) {
				for(int i = 0 ; i < monsters_vec.size() ; i++) {
					Monster *m = monsters_vec[i];
					map[m->y][m->x] = m->GetAppearance();
				}	
		}

		void Draw(vector<Monster*> monsters_vec ) {
			ClearMapArray();
			UpdateMapArray(monsters_vec);

			for(int x = 0 ; x < width+2 ; x++) printf("*");
			printf("\n");
			for(int y = 0 ; y < height ; y++) {
				printf("*");
				for(int x = 0 ; x < width ; x++) {
					printf("%c",map[y][x]);
				}
				printf("*\n");
			}
			for(int x = 0 ; x < width+2 ; x++) printf("*");
			printf("\n");
		}

};

class GameEngine {
	private:
		bool game_running = true;
		Map *map;
		vector<Monster*> monsters_vec;

		void Draw() {
			map->Draw(monsters_vec);
		}

		void HandleUserInput() {
			char ch = getchar();
		}

		void MoveMonsters() {
			for(int i = 0 ; i < monsters_vec.size() ; i++) 
				monsters_vec[i]->Move();	
		}

		void AddMonsterToVector(MonsterGenerationInfo info) {

				Monster * m = NULL;
				if ( strcmp(info.name, "MOLE1") == 0 )
				 	m = new Mole1(map_width, map_height, info.x, info.y);

				if ( strcmp(info.name, "MOLE2") == 0 )
				 	m = new Mole2(map_width, map_height, info.x, info.y);

				if( m != NULL)
					monsters_vec.push_back(m);
		}

		void GenerateMonsters() {
				
				for(int i = 0 ; i < mon_gen_info_vec.size() ; i++) {
					if (mon_gen_info_vec[i].frame == game_frame) {
						AddMonsterToVector(mon_gen_info_vec[i]);	
					}	
				}


		}

		int game_frame;
		int map_width;
		int map_height;

	public:
		GameEngine() {map_width = 20; map_height = 20; game_frame = 0;  map = new Map(map_width,map_height);
		
		}

		vector<MonsterGenerationInfo> mon_gen_info_vec;

		void LoadGameData() {
			FILE *fp = fopen("data.dat","rt");	

			int num_monsters = 0;
			fscanf(fp, "%d", &num_monsters);

			for(int i = 0 ; i < num_monsters ; i++) {
				MonsterGenerationInfo info;
				fscanf(fp,"%d %s %d %d\n",&info.frame, info.name, &info.x, &info.y);
				mon_gen_info_vec.push_back(info);
			}

			fclose(fp);
		}

		void Run() {
			LoadGameData();
			while(game_running) {
				game_frame++;
				GenerateMonsters();	
				MoveMonsters();
				Draw();	
				HandleUserInput();
			}
		} 
};



class Game{
	private:
		GameEngine *engine;

		void ShowTitle() { printf("\nDDJ GAME\nPress Enter key to continue.."); getchar(); }

	public: 
		Game() { engine = new GameEngine(); }

		void Run() {
			ClearDisplay();
			ShowTitle();
			engine->Run();
		}
};
int main(int argc, char* argv[]) {
	Game *game = new Game();
	game->Run();

	return 0;
}
