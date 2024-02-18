#include <iostream>
#include "Lotto.h"

Lotto::Lotto(int row){
    row_ = row+1;
    for(int i = 0; i<row_; i++){
	arr_[i] = new int[6];
    }
}

void Lotto::Run(){
    int r = 0;
    while(1){
	string num;
	cout<<"1. 번호추첨"<<endl;
	cout<<"2. 최근 3개 추첨번호 보기"<<endl;
	cout<<"3. Quit"<<endl;
	cout<<"입력)";
	cin>>num;
	if(num == "1"){
	    num_->Run(arr_[r]); 
	    r++;
	}
	else if(num == "2"){
	    his_->print_num(arr_, r);
	}
	else if(num == "3"){
	    cout<<"Bye"<<endl;
	    break;
	}
	if(r>row_-1){
	    r=row_-1;
	    his_->move(arr_, r+1);
	}
    }

}

