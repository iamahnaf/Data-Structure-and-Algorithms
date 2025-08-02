#include<bits/stdc++.h>
using namespace std;
int lenSubstring(string s){
  int l=0,r=0,maxlen=0;
  //vector<int> hash(256, -1);
  unordered_map<char,int> hash;
  while(r<s.size()){
    if(hash.find(s[r])==hash.end()){
        hash[s[r]]=r;
    }else{
        l=max(l,hash[s[r]]+1);
        hash[s[r]]=r;
    }
    maxlen=max(maxlen,r-l+1);
    r++;
  }
  return maxlen;
}
int main(){
  string s="abcabcbb";
  cout<<lenSubstring(s);
}