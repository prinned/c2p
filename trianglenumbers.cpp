#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

vector<int> factors(int num);

/*
int main(int argc, char** argv){
    for (auto i : factors(stoi(argv[1])))
        cout<<i<<endl;
    return 0;
}
*/

int main (int arg, char** argv){
    bool found = false;
    int natNum = 1;
    int triNum = 1;
    while (!(found)){
        int Size = factors(triNum).size();
        //cout<<triNum<<" : "<<Size<<endl;
        if (Size > stoi(argv[1])) {
            found = true;
            cout<<triNum<<" - "<<Size<<endl<<"| ";
            for (auto i : factors(triNum))cout<<i<<" | ";
        }
        natNum++;
        triNum += natNum;
    }
    return 0;
}
vector<int> factors(int num){
    vector<int> Factors = {1};
    for (int i = 2; i <= num/2; i++){
        if (!(num%i)){
            Factors.push_back(i);
        }
    }
    return Factors.shrink_to_fit;
}

/*
g++ trianglenumbers.cpp -o tri.exe
*/