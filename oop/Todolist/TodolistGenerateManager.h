#ifndef __TODOLISTGENERATEMANAGER_H__
#define __TODOLISTGENERATEMANAGER_H__

using namespace std;

class TodolistGenerateManager{
    private:
    public:
	void make_list(string *todolist_, int &num_);
	void delete_list(string *todolist_, int &num_);
};

#endif
