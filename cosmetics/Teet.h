#ifndef __TEET_H__
#define __TEET_H__
#include <cstring>
#include <iostream> 
#include "Ample.h"
using namespace std;
class Teet:public Ample{
    private:
	string ingre[5];
	void InitIngredient();
    public:
	int num_ingredient;
	Teet();
	void ShowIngredient();
};

#endif
