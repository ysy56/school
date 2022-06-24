#include <iostream>
#include "Todolist.h"

Todolist::Todolist(){}

Todolist::~Todolist(){
    delete generate;
    delete history; 
}
/*
Todolist::Todolist(const Todolist& todo){
    this->num_ = todo.num_;
    for(int i=0;i<num_;i++)
	this->todolist_[i] = todo.todolist_[i];
    this->generate = todo.generate;
    this->history = todo.history;
}
*/
void Todolist::Run(){
    string list;
    while(1){
	cout<<"1. Todo-list 작성"<<endl;
	cout<<"2. Todo-list 삭제"<<endl;
	cout<<"3. Todo-list 보기"<<endl;
	cout<<"4. 종료"<<endl;
	cin>>list;
	cin.ignore();
	if(list == "1")
	    generate->make_list(todolist_, num_);
	if(list == "2")
	    generate->delete_list(todolist_, num_);
	if(list == "3")
	    history->View(todolist_, num_);
	if(list == "4"){
	    cout<<"하루 일과를 종료합니다."<<endl;
	    break;
	}
    }
}
