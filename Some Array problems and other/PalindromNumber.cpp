#include<iostream>
#include<string>
using namespace std;
bool palindrome(int n){
  string s=to_string(n);
  int size=s.size();
  if(size<=1){
    return true;
  }
  if(s[0]==s[size-1]){
     if(size==2){
        return true;
     }
     int x=stoi(s.substr(1,size-2));
     return palindrome(x);
  }else return false;
}
int main(){
    int n=12521;
   cout<<palindrome(n);
}