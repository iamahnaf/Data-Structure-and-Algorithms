#include<bits/stdc++.h>
using namespace std;
bool isValid(string s){
    if(s.size()==1)return false;
    stack<char> stk;
    for(int i=0;i<s.size();i++){
        if( s[i]== '[' || s[i]== '{' || s[i]== '(')
        {
            stk.push(s[i]);
        }else{
           if(stk.empty()) return false;
           char c= s[i];
           if(c == ')' && stk.top() != '(' ||
              c== '}' && stk.top() != '{' ||
              c==']' && stk.top()  != '[')
              {
                return false;
              }
              stk.pop();
        }
    }
    return stk.empty();
}
int main(){
    string s="[{()}]";
    cout<<isValid(s);
}