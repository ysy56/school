#include <iostream>
#include "LottoHistoryManager.h"

void LottoHistoryManager::move(int **arr, int r){
    for(int i = 1; i<r; i++){
	for(int j = 0; j<6; j++){
	    arr[i-1][j] = arr[i][j];
	}
    }
}

void LottoHistoryManager::print_num(int **arr, int r){
    cout<<"최근 3개 추첨번호"<<endl;
    for(int i = 0; i<r; i++){
	cout<<i+1<<" : ";
	for(int j = 0; j<6; j++){
	    cout<<arr[i][j]<<" ";
	}
	cout<<endl;
    }
}
