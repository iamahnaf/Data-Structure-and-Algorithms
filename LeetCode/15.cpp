#include<bits/stdc++.h>
using namespace std;
void threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end()); 
    int target=0;
    int l,r;
    vector<vector<int>> v;
    //unordered_set<int> hash;
    for(int i=0;i<nums.size();i++){
        if( i > 0 && nums[i]==nums[i-1]) continue;
        l=i+1;
        r=nums.size()-1;
        int diff=target-nums[i];
        while(l < r){
            if(diff >  nums[l]+nums[r]){
                l++;
            }else if( diff < nums[l]+nums[r]){
                r--;
            }else{
                vector<int> temp={nums[i],nums[l],nums[r]};
                v.push_back(temp);
                l++;
                r--;
                while(l < r && nums[l]==nums[l-1]) l++;
                while(l < r && nums[r]==nums[r+1]) r--;
            }
        }
        
    }  
   for(auto it : v){
    for(auto vec: it){
        cout<<vec<<" ";
    }
    cout<<endl;
   }
   //return ans;
}
int main(){
   vector<int> v={-1,0,1,2,-1,-4};
   //vector<vector<int>> x=threeSum(v);
   threeSum(v);
}