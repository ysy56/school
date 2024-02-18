#include "Monster.h"

Monster* Monster::add(Monster *m){
    this->next = m;
    return m;
}

void Monster::move(){
    move();
    cout<<"Monster move"<<endl;
}
