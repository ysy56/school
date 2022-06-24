#include "Ample.h"
#include "BasicCare.h"
using namespace std;

Ample::Ample(){
    cout<<"Ample클래스 생성되었습니다"<<endl;
    this->num_characteristic = 3;
    InitCharacteristic();
}

void Ample::InitCharacteristic(){
    characteristic[0] = "촉촉한";
    characteristic[1] = "끈적하지않은";
    characteristic[2] = "진정되는";
    characteristic[3] = "흡수되는";
    characteristic[4] = "밀착되는";
}

void Ample::ShowCharacteristic(){
    ShowPurposeOfUse();
    for(int i = 0; i<num_characteristic; i++){
	cout<<"특성"<<i+1<<":"<<characteristic[i]<<endl;
    }
}
