#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

string VtoS(vector<string> myVec, string myJoiner);
string trim_ws(string inString);

int main(){
    cout<<VtoS({"a","b","c","dummy mummy"},"\n");
    return 0;
}

string VtoS(vector<string> myVec, string myJoiner){
    string fString=myVec[0];
    for (int i = 1; i < myVec.size(); i++)
        fString+= myJoiner + myVec[i];
    return fString;
}

string trim_ws(string inString){
    
}