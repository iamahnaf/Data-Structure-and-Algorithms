#include<bits/stdc++.h>
using namespace std;
int rodCutting(vector<int> price,vector<int> len,int rod){
    int n=price.size();
    vector<vector<int>> dp(n+1,vector<int>(rod+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<rod+1;j++){
            if(i==0 || j==0)
            dp[i][j]=0;
        }
    }
    for(int i=1;i<n+1;i++)
      for(int j=1;j<rod+1;j++){
         //valid
         if(len[i-1] <= j){
            dp[i][j]=max(price[i-1] + dp[i][j-len[i-1]],dp[i-1][j]);
         }else{
            dp[i][j]=dp[i-1][j];
         }
      }
      return dp[n][rod];
}
int main(){
    vector<int> length={1,2,3,4,5,6,7,8};
    vector<int> price={1,5,8,9,10,17,17,20};
    int rod=8;
    cout<<rodCutting(price,length,rod);
}