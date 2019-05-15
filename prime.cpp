#include <vector>
#include <iostream>
#include <cmath>
#include<string>

bool isPrime(int inint){
    if (inint <= 1) return false;
    for ( int i = 2; i<=ceil(pow(inint,0.5));i++ ){
        if (inint%i==0) return false;
    }
    return true;
}

std::vector<int> getPrimes(int maxPrime){
    std::vector<int> primelist = {2};
    for (int i = 3; i <= maxPrime; i+=2) 
        if (isPrime(i))
            primelist.push_back(i);
    return primelist;
}

int main(int argc, char** argv){
    std::cout.setf(std::ios::boolalpha);

    std::cout<<isPrime(std::stoi(argv[1]))<<"\n\n";
    for (int i : getPrimes(std::stoi(argv[2]))) std::cout<<i<<'\n';
    return 0;
}