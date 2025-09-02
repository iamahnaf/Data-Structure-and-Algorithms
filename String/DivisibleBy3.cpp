#include <cmath>
#include <cstdio>
#include <vector>
#include<string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    getline(cin,s);
    long long value=0;
    for(char c: s){
        if(isdigit(c)){
            value=value+c-'0';
        }
     }
     if(value%3==0){
        cout<<"YES"<<endl;
     }else cout<<"NO"<<endl;
    return 0;
}
