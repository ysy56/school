#ifndef __PIZZAMANAGER_H__
#define __PIZZAMANAGER_H__
#include "Pizza.h"
using namespace std;

class PizzaManager{
    private:
	int num = 0;
	string t[5];
	string e[5];
    public:
	void set_all_toping_edge(string toping, string edge);
	Pizza* CreatePizza(string toping="추가 토핑 없음", string edge="에지 없음");
	void PrintAllPizzaInfo();
};

#endif
