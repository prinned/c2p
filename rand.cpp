#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    while(true){
        srand(time(NULL));
        int myRandint = rand();
        cout<<myRandint<<endl;
    }
    return 0;
}