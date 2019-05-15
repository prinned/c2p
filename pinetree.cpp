#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//syntax: something.exe <start> <end> <increment>
int main(int argc, char** argv){
    int rows = stoi(argv[1]);
   for (int i = 0; i<rows; i++){
       for(int j = 1; j<rows-i; j++){
           cout<<' ';
       }
       cout<<'#';
       for(int j = 0; j<i*2; j++){
           cout<<'#';
       }
       cout<<endl;
   }
   for (int i=0; i<rows-1;i++){
       cout<<' ';
   }
   cout<<'#';
}