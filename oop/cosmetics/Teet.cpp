#include "Teet.h"
#include "Ample.h"
using namespace std;

Teet::Teet(){
    cout<<"Teet클래스 생성되었습니다"<<endl;
    this->num_ingredient = 3;
    InitIngredient();
}

void Teet::InitIngredient(){
    ingre[0] = "티트리잎수";
    ingre[1] = "마머카소사이드";
    ingre[2] = "레시틴";
    ingre[3] = "앞지닌";
    ingre[4] = "글루코오스";
}

void Teet::ShowIngredient(){
    ShowCharacteristic();
    for(int i = 0; i<this->num_ingredient; i++){
	cout<<"성분"<<i+1<<":"<<this->ingre[i]<<endl;
    }
}
