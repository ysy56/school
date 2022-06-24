#include <iostream>
#include "Pizza.h"
#include "PizzaManager.h"
using namespace std;

int main(){
    PizzaManager *pm = new PizzaManager();
    Pizza *basicPizza = pm->CreatePizza();
    Pizza *cheesePizza = pm->CreatePizza("Cheese");
    Pizza *bulgogiEdgePizza = pm->CreatePizza("Bulgogi", "Sweet Potato");

    cout<<endl<<"Total Pizza in Pizza class = "<<Pizza::GetPizzaCount()<<endl;
    pm->PrintAllPizzaInfo();
    cout<<endl<<"bulgogiEdgePizza 정보: "<<bulgogiEdgePizza->PrintPizzaInfo()<<endl;
    return 0;
}
