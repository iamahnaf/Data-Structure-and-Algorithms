#include<bits/stdc++.h>
using namespace std;
int threeSum(vector<int>& nums) {
    int target=8;
    vector<vector<int>> v;
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int count=0,l,r;
    int mod=1e9+7;
    for(int i=0;i<nums.size();i++){
      l=i+1;
      r=n-1; int diff=target-nums[i];
      while(l<r){
        if(nums[l]+nums[r]==diff){
          vector<int> temp={nums[i],nums[l],nums[r]};
          v.push_back(temp);
          l++;
        }else if(nums[l]+nums[r] < diff){
          l++;
        }else{
          r--;
        }
      }
       
    }  
   return v.size();
 }
 int main(){
   vector<int> v={1,1,2,2,3,3,4,4,5,5};
 
   cout<<threeSum(v);
   
}