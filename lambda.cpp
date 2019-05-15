#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <functional>

std::vector<int> randVector(int total=10, int start = 0, int end = 100){
    srand(time(NULL));
    std::vector<int> outvec(total);
    for (int i = 0; i < total; i++){
        outvec.push_back( rand() % (end-start) + start);
    }
    return outvec;
}

int main(int argc, char** argv){
    std::vector<int> outvec;
    std::function<int(int)> fib = [&fib](int x){return (x < 2) ? x : fib(x-1) + fib(x-2);};
    for (int i = 1; i <= std::stoi(argv[1]);i++){
        outvec.push_back(fib(i));
    }

    for (int i : outvec) std::cout<<i<<'\n';
    return 0;
}