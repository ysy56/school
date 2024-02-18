#ifndef __TODOLIST_H__
#define __TODOLIST_H__
#include "TodolistGenerateManager.h"
#include "TodolistHistoryManager.h"

using namespace std;

class Todolist{
    private:
	int num_ = 0;
	string todolist_[5];
	TodolistGenerateManager *generate = new TodolistGenerateManager();
	TodolistHistoryManager *history = new TodolistHistoryManager();
    public:
	//Todolist(const Todolist& todo);
	Todolist();
	~Todolist();
	void Run();
};

#endif
