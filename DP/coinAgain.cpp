#include<iostream>
#include<vector>
using namespace std;
int coins(vector<int> coin,int amount){
    if(amount==0){
        return 0;
    }
    if(amount < 0){
        return INT16_MAX;
    }
    int mini=INT16_MAX;
    for(int i=0;i<coin.size();i++){
        int ans=coins(coin,amount-coin[i]);
        if(ans != INT16_MAX){
            mini=min(mini,1+ans);
        }
    }
    return mini;
}
int coinTab(vector<int> coin,int amount){
   vector<int> dp(amount+1,INT16_MAX);
   dp[0]=0;
   for(int i=1;i<=amount;i++){
    for(int j=0;j<coin.size();j++){
        if(i >= coin[j] && dp[i-coin[j]] != INT16_MAX){
            dp[i]=min(dp[i],1+dp[i-coin[j]]);
        }
      }
   } 
   if(dp[amount] == INT16_MAX){
    return -1;
   }
   return dp[amount];
}
int main(){
    vector<int> coin={1,2,5};
    int amount=11;
    cout<<coinTab(coin,amount);
}