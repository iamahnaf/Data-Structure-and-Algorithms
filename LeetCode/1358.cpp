#include<bits/stdc++.h>
using namespace std;
int numOfString(string s){
    int l=0,r=0,nums=0;
    unordered_map<char,int> m; int n=s.size();
    while(r<s.size()){
        m[s[r]]++;
        cout<<m.size()<<endl;
        while(m['a'] > 0 && m['b'] > 0 && m['c'] > 0){ //abcabc
           nums=nums+ n - r;
           m[s[l]]--;
           l++;
        }
        r++;
        
    }
    return nums;
}
int main(){
  string s="aaacb";
  cout<<numOfString(s);
}
