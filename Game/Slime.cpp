#include "Slime.h"
#include "Stone.h"

void Slime::Move(){
    cout<<"Slime: 다가온다."<<endl;
    cout<<"Player Hp -3"<<endl;
    Stone *st = new Stone();
    st.Move;
}

void Slime::Apear(){
    cout<<"Slime 발견"<<endl;
}

