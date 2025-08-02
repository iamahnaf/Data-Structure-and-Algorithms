#include<bits/stdc++.h>
using namespace std;
void helper(vector<int> &arr, vector<vector<int>> &ans, int idx,vector<int> &temp){
    if(idx==0){
        ans.push_back(temp);
    }
    helper(arr,ans,idx-1,temp.)

}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(nums,ans);
        return ans;
}
int main(){

}