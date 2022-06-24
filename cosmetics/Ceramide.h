#ifndef __CERAMIDE_H__
#define __CERAMIDE_H__
#include <iostream> 
#include <string>
#include "Ample.h"
using namespace std;

class Ceramide : public Ample{
    private:
	string ingre[5];
	void InitIngredient();
    public:
	int num_ingredient;
	Ceramide();
	void ShowIngredient();
};

#endif
