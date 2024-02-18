#ifndef __LOTTO_H__
#define __LOTTO_H__
#include "LottoNumberGenerator.h"
#include "LottoHistoryManager.h"

using namespace std;

class Lotto{
    private:
	int row_;
	int **arr_ = new int*[row_];
	LottoNumberGenerator *num_ = new LottoNumberGenerator();
	LottoHistoryManager *his_ = new LottoHistoryManager;
    public:
	Lotto(int row);
	void Run();
};

#endif
