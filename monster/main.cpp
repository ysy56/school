#include <iostream>
#include "Monster.h"
#include "Orc.h"
#include "Slime.h"

using namespace std;

int main(){

    Monster *m1 = new  Slime();
    Monster *m2 = new  Orc();

    m1->move();
    m2->move();
    
    Monster *mStar=NULL;
    Monster *mLast;

    mStar = new Slime();
    mLast = mStar;

    mLast = mLast->add(new Orc());
    mLast = mLast->add(new Slime());

    Monster* m = mStar;
    while(m != NULL){
	m->move();
	m = m->getNext();
    }
    return 0;
}
