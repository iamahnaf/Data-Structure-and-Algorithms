#include<bits/stdc++.h>
using namespace std;
int maxscore(vector<int> v,int k){
    int n=v.size();
    int subArraysize=n-k;
    int minSub=0,subarr=0;
    int totalSum=accumulate(v.begin(),v.end(),0);
    if(k==n) return totalSum;
    for(int i=0;i<subArraysize;i++){
        subarr=subarr+v[i];
    }
    minSub=subarr;
    for(int r=subArraysize; r < n ; r++){
        subarr = subarr - v[r - subArraysize ] + v[r];
        minSub=min(minSub,subarr);
    }
    return totalSum - minSub;
}
int main(){
    vector<int> v={100,40,17,9,73,75};
    cout<<maxscore(v,3);
}