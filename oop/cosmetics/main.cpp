#include <iostream>
#include "BasicCare.h"
#include "Ample.h"
#include "Teet.h"
#include "Ceramide.h"
using namespace std;

int main(){
    BasicCare bc;
    Ample a;
    Ceramide d;
    Teet t;

    t.ShowPurposeOfUse();
    d.ShowCharacteristic();
    
    // 업 캐스팅
    Teet *tDer;
    Ample *aBase = &t;
    
    aBase->ShowCharacteristic();

    // 다운 캐스팅
    tDer = (Teet*)aBase;
    tDer->ShowIngredient();

    return 0;
}
