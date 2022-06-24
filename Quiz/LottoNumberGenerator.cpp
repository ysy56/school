#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "LottoNumberGenerator.h"

void LottoNumberGenerator::Run(int *arr){
    make_num(arr);
    sort(arr);
    print_num(arr);
}

void LottoNumberGenerator::make_num(int *arr){
    srand(time(NULL));
    int random = 0;
    for(int i = 0; i<6; i++){
	random = rand()%45+1;
	arr[i] = random;
	for(int j = 0; j<i; j++){
	    if(arr[j]==random)
		i--;
	}
    }   
}

void LottoNumberGenerator::sort(int *arr){
    for(int i = 0; i<5; i++){
	for(int j = i+1; j<6; j++){
	    if(arr[i]>arr[j]){
		int tmp;
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	    }
	}
    }
}

void LottoNumberGenerator::print_num(int *arr){
    cout<<"생성된 추첨번호:"<<endl;
    for(int i = 0; i<6; i++){
	cout<<arr[i]<<" ";
    }
    cout<<endl;
}
