#include <iostream>
#include "PizzaManager.h"

int Pizza::count = 0;

void PizzaManager::set_all_toping_edge(string toping, string edge){
    t[num] = toping;
    e[num] = edge;
    num++;
}

Pizza* PizzaManager::CreatePizza(string toping, string edge){
    if(toping != "추가 토핑 없음")
	toping.append(" 토핑 추가");
    if(edge != "에지 없음")
	edge.append(" 에지 추가");
    cout<<"피자 생성됨:"<<toping<<", "<<edge<<endl;
    set_all_toping_edge(toping, edge);
    Pizza *p = new Pizza();
    Pizza::count++;
    p->set_toping_edge(toping, edge);
    return p;
}

void PizzaManager::PrintAllPizzaInfo(){
    for(int i = 0; i<num; i++){
	cout<<"피자"<<i+1<<":"<<t[i]<<", "<<e[i]<<endl;
    }
}

