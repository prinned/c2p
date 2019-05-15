#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;


double solve(string instring){
    //parsing for vals
    stringstream instream (instring);
    string mytoken;
    vector<string> values; //value array
    while(getline(instream, mytoken, ' ')&&values.size() <= 5 ){
        values.push_back(mytoken);
    }
    if (values[1] == "="){
        reverse(values.begin(),values.end());
    }

    char Operator = values[1][0];
    double endval = stoi(values[4]);
    double num1;
    if (isalpha((int)values[0][0])){
        num1 = stoi(values[2]);
    } else if (isalpha(values[2][0])){
        num1 = stoi(values[0]);
    } else{
        cout<<"Invalid Syntax: no Variable";
    }

    //end parsing


    
    double xval;
    switch (Operator){
        case '+':
            xval = endval - num1;
            break;
    
        case '-':
            xval = endval + num1;
            break;

        case '*':
            xval = endval / num1;
            break;
        
        case '/':
            xval = endval * num1;
            break;

        case '%':
            throw "Modular Arithmetic not compatible";
            break;
        
        default:
            throw "Invalid Syntax";
            break;
    } 

    return xval;
}


int main(){
    string instring;
    getline(cin, instring);
    cout<<solve(instring);
}