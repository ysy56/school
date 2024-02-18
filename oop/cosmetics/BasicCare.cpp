#include "BasicCare.h"

BasicCare::BasicCare(){
    cout<<"BasicCare클래스 생성되었습니다"<<endl;
    num_ranking = 5;
    InitPurposeOfUse();
}

void BasicCare::InitPurposeOfUse(){
    purpose_of_use = "스킨 케어";
}

void BasicCare::ShowPurposeOfUse(){
    cout<<"사용용도:"<<purpose_of_use<<endl;
}

void BasicCare::ShowRanking(){
    cout<<"순위"<<num_ranking<<"까지 표시"<<endl;
}
