#include<bits/stdc++.h> 
using namespace std;

int minCostClimbingStairs(vector<int>& cost, int n,vector<int> &dp) {
    if (n == 0 || n == 1) {
        return cost[n];
    }
    if(dp[n] != -1){
        return dp[n];
    }

    int left = minCostClimbingStairs(cost, n-1,dp);
    int right = minCostClimbingStairs(cost, n-2,dp);
    return dp[n]=cost[n] + min(left, right);
}

int main() {
    vector<int> cost = {10, 15, 20};
   
    int n = cost.size();
    vector<int> dp(cost.size(),-1);
   cout << min(minCostClimbingStairs(cost, n-1,dp), minCostClimbingStairs(cost, n-2,dp));
}
