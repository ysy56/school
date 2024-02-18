#include <iostream>
#include "Todolist.h"
#include "TodolistGenerateManager.h"
#include "TodolistHistoryManager.h"

using namespace std;

int main(int argc, char* argv[]){
    Todolist todo ;
    todo.Run();
    
    cout<<"다음 날 Todo-list"<<endl; 
    Todolist *todo_next = new Todolist(todo);

    todo_next->Run();
    delete todo_next;
    return 0;
}
