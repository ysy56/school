#include <iostream>
#include <string>
#include "TodolistGenerateManager.h"

void TodolistGenerateManager::make_list(string *todolist_, int &num_){
    cout<<"Todo-list를 작성해주세요"<<endl;     
    getline(cin, todolist_[num_]);
    num_++;   
}

void TodolistGenerateManager::delete_list(string *todolist_, int &num_){
    int n;
    cout<<"삭제할 Todo-list 번호를 입력해주세요"<<endl;
    cin>>n;
    for(int i = n-1; i<num_-1; i++){
	todolist_[i] = todolist_[i+1];
    }
    todolist_[num_-1].clear();
    num_--;
}
