#ifndef __AMPLE_H__
#define __AMPLE_H__
#include <cstring>
#include <iostream> 
#include "BasicCare.h"
using namespace std;

class Ample:public BasicCare{
    private:
	string characteristic[5];
	void InitCharacteristic();
    public:
	int num_characteristic;
	Ample();
	void ShowCharacteristic();
};

#endif
