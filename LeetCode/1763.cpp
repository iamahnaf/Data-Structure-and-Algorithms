#include<bits/stdc++.h>
using namespace std;

string longestNiceSubstring(string s) {
   if(s.size() < 2) return "";
    unordered_set<char> hash(s.begin(),s.end());
   
   for(int i=0;i<s.size();++i){
      if( hash.count(tolower(s[i])) && hash.count(toupper(s[i])) ){
        continue;
      }
      string left=longestNiceSubstring(s.substr(0,i));
      string right=longestNiceSubstring(s.substr(i+1));
      return left.size() >= right.size() ? left : right;
   }
   return s;
}
int main(){
    string s="dDzeE";
    cout<<longestNiceSubstring(s);
}