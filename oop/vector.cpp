#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    vector<vector<int>> r;
    r[0].push_back(1);
    r[0].push_back(2);
    r[0].push_back(3);

    r[1].push_back(4);
    r[1].push_back(5);
    r[1].push_back(6);

    r[2].push_back(7);
    r[2].push_back(8);
    r[2].push_back(9);

    for(int j = 0; j<3; j++){
	for(int i = 0; i<3; i++){
	    cout<<r[j][i];
	}
    }
}
