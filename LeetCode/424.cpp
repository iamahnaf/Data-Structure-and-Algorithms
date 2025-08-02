#include<bits/stdc++.h>
using namespace std;
int numbers(string s,int k){
    int l=0,r=0,maxlen=0,maxf=0;
    unordered_map<char,int> hash;
    int n=s.size();   //A A B A B B A

    while(r<n){
      hash[s[r]]++;
      maxf=max(maxf,hash[s[r]]);
      cout<<"maxf- "<<maxf<<endl;
      if( r-l+1 - maxf > k ){
         hash[s[l]]--;
         l++;
      }
     if((r-l+1) - maxf <= k){
        maxlen=max(maxlen, r - l +1);
        r++;
     }
    }
    return maxlen;
}
int main(){
    string s="AABABBA";
    cout<<numbers(s,1);
}