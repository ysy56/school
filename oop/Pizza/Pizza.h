#ifndef __PIZZA_H__
#define __PIZZA_H__
using namespace std;

class Pizza{
    string toping;
    string edge;
    public:
	static int count;
	void set_toping_edge(string toping, string edge);
	static int GetPizzaCount(){
	    return count;
	};
	string PrintPizzaInfo();
};

#endif
