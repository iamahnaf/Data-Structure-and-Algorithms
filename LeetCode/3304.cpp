#include<math.h>
#include<string>
#include<iostream>
using namespace std;
char nextChar(char c) {
        return (c == 'z') ? 'a' : c + 1;  
}
char helper(string s,int k){
    if(k < s.size()){
        return s[k];
    }
    string next="";
    for(char c:s){
        next+=nextChar(c);
    }
    return helper(s+next,k);
}
int main(){
    string x="a";
    cout<<helper(x,5);
}