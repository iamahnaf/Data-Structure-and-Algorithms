#include<bits/stdc++.h>
using namespace std;
bool palindromic(string s){
    int len=s.length();
    if(len<=1){
        return true;
    }
    if(s[0]==s[len-1]){
        return palindromic(s.substr(1,len-2));
    }else return false;
}
string palindrom(string s){
    int ans=palindromic(s);
    int n=s.size();
    if(ans){
        return s;
    }else{
        string left=palindrom(s.substr(0,n-1));
        string right=palindrom(s.substr(1));
        return left.size() > right.size() ? left : right;
    }
}
int main(){
    string s="cbbd";
    cout<<palindrom(s);
}