#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv){
    std::string sInfile = argv[1];
    std::ifstream read_file(sInfile, std::ios_base::in);
    std::string temp_str;
    unsigned int words_cnt = 0;
    unsigned int char_cnt = 0;

    if (read_file.is_open()){
        while (read_file.good()){
            while(getline(read_file, temp_str,' ')){
                if(temp_str.find_first_not_of("\t\n\v\r") != std::string::npos){
                    words_cnt++;
                    char_cnt += temp_str.size();
                }
            }
        }
    }



    std::cout<<"Word count: "<<words_cnt<<'\n';
    std::cout<<"Average word length: "<<char_cnt/(double)words_cnt<<'\n';
    return 0;
}