#include <iostream>
#include "TodolistHistoryManager.h"

void TodolistHistoryManager::View(string *todolist_, int &num_){
    cout<<"Todo-list View"<<endl;
    for(int i = 0; i<num_; i++){
	cout<<i+1<<":"<<todolist_[i]<<endl;
    }
}

