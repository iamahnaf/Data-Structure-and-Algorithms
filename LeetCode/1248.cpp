#include<bits/stdc++.h>
using namespace std;
int binary(vector<int> v, int k){
    if(k < 0 ) return 0;
    int l=0,r=0,sum=0,count=0,n=v.size();

    while(r<n){   //1,1,2,1,1
       sum=sum+ (v[r]%2);
       cout<<"sum- "<<sum<<endl;
       while(sum > k){
          sum=sum-(v[l]%2);
          cout<<"new sum - "<<sum<<endl;
          l++;
       }
       count=count+(r-l+1);
       cout<<"Count- "<<count<<endl;
     r++;
    }
  return count;
}
int main(){
   vector<int> v={1,1,2,1,1};
   cout<<binary(v,3);
}