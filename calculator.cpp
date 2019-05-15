#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define min(a, b) ((a<b)?a:b)
#define max(a, b) ((a>b)?a:b)


vector<string> mysplit(string myString, char myDelim){
    std::stringstream myStream (myString);
    string myToken;
    vector<string> mySplitted;
    while(getline(myStream, myToken, myDelim)){
      mySplitted.push_back(myToken);
    }
    return mySplitted;
}


int main(int argc, char** argv){
  double num1, num2;
  string op;

  if (argc == 4){ //assigns vars using cmd
    double num1 = stoi(argv[1]);
    string op = argv[2];
    double num2 = stoi(argv[3]);
    cout<<"it did the cmd thing";
    
  }else{    //assigns n1, n2, op through cin
    cout<<"enter: ";
    string myInput;
    getline(cin,myInput);
    vector<string> input = mysplit(myInput, ' ');


    if (input.size() !=3) {
    cout<<"Syntax error: too many/few arguments passes";
    return 1;
    }


    double num1 = stoi(input[0]);
    string op = input[1];
    double num2 = stoi(input[2]);
  }

  cout<<"num1 - "<<num1<<"\nop - "<<op<<"\nnum2 - "<<num2;

	double answer;
  if (op=="+"){
  answer = num1 + num2;
  }else if (op=="-"){
  answer = num1 + num2;
  }else if (op=="/"){
  answer = num1 / num2;
  }else if (op=="*"){
  answer = num1 * num2;
  }else if (op=="^"){
  answer = pow(static_cast<unsigned int>(num1),static_cast<int>(num2));
  }else if (op=="%"){
  answer = static_cast<int>(num1) % static_cast<int>(num2);
  }else{
      cout<<"syntax eroor bro come on";
      cout<<endl<<op;
      return 2;
  }

  cout<<num1<<" "<<op<<" "<<num2<<" = "<<answer;
  return 0;
}
//		answer = pow(static_cast<unsigned int>(num1),static_cast<int>(num2));
