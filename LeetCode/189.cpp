#include<bits/stdc++.h>
using namespace std;
void rotate1(vector<int>& nums, int k) { //Time limit 
    //int last=nums.size()-1;
    while (k>0)
    {
        int last=nums.size()-1;
        for(int i=1;i<nums.size();i++){
        swap(nums[last-1],nums[last]);
        last--;
         }
         k--;
    }
     
    for(auto it:nums){
        cout<<it<<" ";
    }   
}
void rotate(vector<int> &nums,int k){
    if(nums.size()==1){
        return;
    }
    k=k % nums.size();
    vector<int> v(nums.size());
     int idx=nums.size()-k; int j=0;
     for(int i=idx;i<nums.size();i++){
        v[j++]=nums[i];
     }
     int i=0;
     while(idx>0){
       v[j++]=nums[i++];
       idx--;
     }
     copy(v.begin(),v.end(),nums.begin());
     for(auto it:nums){
        cout<<it<<" ";
     }
}
int main(){
  vector<int> v={1,2,3,4,5,6,7};
  int k=3; 
  rotate(v,k);
  
}