#include<iostream>
using namespace std;
int countways(int n,int dp[]){
   if(n<0)return 0;
    if(n==0){
      return 1;
    }
    if(dp[n]!= -1){
      return dp[n];
    }
    dp[n]=countways(n-1,dp)+countways(n-2,dp);
    return dp[n];
}
int countwaysTabulation(int n){
     int dp[n+1];
     dp[0]=1;
    for(int i=1;i<=n;i++){
      if(i==1) dp[i]=dp[i-1];
      else
      dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n=5; int dp[n+1];
    fill(dp,dp+n+1,-1);
    cout<<countways(5,dp)<<endl;
    cout<<countwaysTabulation(5);
    
}