#include<bits/stdc++.h>
using namespace std;
int longestOne(vector<int> v,int k){
    queue<int> minheap;
    int l=0,r=0,maxlen=0; int zeroCount=0;
    int n=v.size();  //1,1,1,0,0,0,1,1,1,1,0
    while(r<n){
       if(v[r]!=0){
         maxlen=max(maxlen, r - l +1);
         
       }else{
        zeroCount++;
        minheap.push(r);
           if(zeroCount<=k){
              maxlen=max(maxlen, r - l + 1);
           }else{
             l=minheap.front()+1;
             minheap.pop();
           }
       }
       r++;
    }
    return maxlen;
}
int main(){
   vector<int> v={0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
   cout<<longestOne(v,3);
}