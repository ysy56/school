#include <iostream>
#include "Pizza.h"

void Pizza::set_toping_edge(string toping, string edge){
    this->toping = toping;
    this->edge = edge;
}

string Pizza::PrintPizzaInfo(){
    string str;
    str.append(toping);
    str.append(", ");
    str.append(edge);
    return str;
}

