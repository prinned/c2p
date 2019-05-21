#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <ctime>

std::vector<int> change_list(std::vector<int> invec, std::function<bool(int)> infunc){
    std::vector<int> outvec;
    for (int i : invec){
        if (infunc(i)) outvec.push_back(i);
    }
    return outvec;
}

void flip(int flip_count){
    srand(time(NULL));
    std::vector<bool> outvec;
    outvec.reserve(flip_count);
    int head_cnt = 0;
    for (int i = 0; i < flip_count; i++){
        bool rand_bool = rand() % 2;
        if (rand_bool) head_cnt++;
        outvec.push_back(rand_bool);
    }
    std::cout<<"Number of heads: "<<head_cnt
             <<"\nNumber of tails: "<<(flip_count - head_cnt);
}

int main(int argc, char const *argv[])
{
    flip(100);
}
