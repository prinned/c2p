#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

void printArray(std::vector<std::string>& inVec){
    //top dashes
    for (std::string i : inVec ){
        std::cout<<"|";
        for (char j : i){
            std::cout<<'-';
        }
        std::cout<<"--";
    }
    std::cout<<'|';
    //end top dashes 

    //numbering
    std::cout<<"\n| ";
    for (int i = 0; i< inVec.size(); i++){
        for (int j = 1; j < (inVec[i].size() / ((std::string)"0").size() ); j++){  // does action string length times
           std::cout<<' ';
        }
        std::cout<<i<<" | ";
    }
    std::cout<<'\n';
    //end numbering

    //middle dashes
    for (std::string i : inVec ){
        std::cout<<"|";
        for (char j : i){
            std::cout<<'-';
        }
        std::cout<<"--";
    }
    //end middle dashes

    //array
    std::cout<<'|';
    std::cout<<"\n| ";
    for (int i = 0; i< inVec.size(); i++){
        std::cout<<inVec[i]<<" | ";
    }
    std::cout<<'\n';
    //end array

    //last dashes
    for (std::string i : inVec ){
        std::cout<<"|";
        for (char j : i){
            std::cout<<'-';
        }
        std::cout<<"--";
    }
    std::cout<<"|";
    //end last dashes
}

int main(){
    std::vector<std::string> inVec = {"1","2","abcdefg","4","x","y","44"};
    printArray(inVec);
}