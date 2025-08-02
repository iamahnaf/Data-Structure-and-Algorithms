#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
   int n=prices.size();
   vector<vector<int>> dp(n,vector<int>(2,0));
   dp[0][0]=0; 
   dp[0][1]= -prices[0];
    for(int i=1;i<n+1;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);   // selling
        dp[i][1]=max(dp[i-1][1],dp [i-1][0] - prices[i]);
    }
  return dp[n-1][0];
}
int main(){

}