#include <iostream>
#include "Lotto.h"
#include "LottoNumberGenerator.h"
//#include "LottoHistoryManager.h"

using namespace std;

int main(int argc, char* argv[]){
    Lotto *lotto = new Lotto(4);
    lotto->Run();
    return 0;
}
