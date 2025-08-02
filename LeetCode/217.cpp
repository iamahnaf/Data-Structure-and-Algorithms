#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(auto it:nums){
        if(it==it+1){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> nums={1,2,3,4,1};
    cout<<containsDuplicate(nums);
}