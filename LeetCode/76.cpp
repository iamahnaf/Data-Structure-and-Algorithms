#include<bits/stdc++.h>
using namespace std;
string minWindow(string s, string t){
    int l=0,r=0,count=0,minlen=INT_MAX,FirstIndex= -1,n=s.size(),m=t.size();
    //unordered_map<char,int> hash;
    vector<int> hash(256,0);
    for(char c: t){
        hash[c]++;
    }
    int mapsize=hash.size();
    while(r < n){
       if( hash[s[r]] > 0 ){
        count++;
       }
       hash[s[r]]--;
      while (count==m){
         if( r-l+1 < minlen){
            minlen= r-l+1;
           FirstIndex= l;
         }
         hash[s[l]]++;
         if(hash[s[l]] > 0 ) count--;
         l++;
       }
       r++;
    }
    return FirstIndex == -1 ? "" : s.substr(FirstIndex,minlen);
}
int main(){
    string s="aa";
    string t="aa";
    cout<<minWindow(s,t);
}