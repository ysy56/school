#include "Ceramide.h"
#include "Ample.h"
using namespace std;

Ceramide::Ceramide(){
    cout<<"Ceramide클래스 생성되었습니다"<<endl;
    this->num_ingredient = 1;
    InitIngredient();
}

void Ceramide::InitIngredient(){
    ingre[0] = "베타인";
    ingre[1] = "아메노신";
    ingre[2] = "잔탄검";
    ingre[3] = "옥틸도데칸올";
    ingre[4] = "카보머";
}


void Ceramide::ShowIngredient(){
    ShowCharacteristic();
    for(int i = 0; i<this->num_ingredient; i++){
	cout<<"성분"<<i+1<<":"<<this->ingre[i]<<endl;
    }
}
