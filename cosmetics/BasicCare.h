#ifndef __BASICCARE_H__
#define __BASICCARE_H__
#include <cstring>
#include <iostream> 
using namespace std;

class BasicCare{
    private:
	string purpose_of_use;
	void InitPurposeOfUse();	
    public:
	int num_ranking;
	BasicCare();
	void ShowPurposeOfUse();
	void ShowRanking(); 
};

#endif
