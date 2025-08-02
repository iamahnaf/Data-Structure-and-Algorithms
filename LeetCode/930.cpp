#include<bits/stdc++.h>
using namespace std;
int binary(vector<int> v, int k){
    if(k < 0 ) return 0;
    int l=0,r=0,sum=0,count=0,n=v.size();

    while(r<n){   //1,0,1,0,1
       sum=sum+v[r];
       while(sum > k){
          sum=sum-v[l];
          l++;
       }
      
       count=count+(r-l+1);
     r++;
    }
  return count;
}
int main(){
   vector<int> v={1,0,1,0,1};
   cout<<binary(v,2)-binary(v,1);
}