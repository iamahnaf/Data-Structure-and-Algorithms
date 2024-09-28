#include<iostream>
#include<vector>
using namespace std;
int change(vector<int> coins, int sum) {
    int n = coins.size();
    int dp[n + 1][sum + 1];
    
    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;  
    }
    
    for (int j = 1; j <= sum; j++) {
        dp[0][j] = sum + 1;  
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (coins[i-1] <= j) {
         
                dp[i][j] = min(dp[i-1][j], dp[i][j - coins[i-1]] + 1);
            } else {
        
                dp[i][j] = dp[i-1][j];
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return dp[n][sum] > sum ? -1 : dp[n][sum];
}
int coinChange(vector<int> coins,int sum){
    int n=coins.size();
    int dp[n+1][sum+1];  //i coins, j sum
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<sum+1;i++){
        dp[0][i]=0;
    }
    //n*sum
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coins[i-1] <= j){
                dp[i][j]=dp[i][j-coins[i-1]] +dp[i-1][j];
                
            }else{
                dp[i][j]=dp[i-1][j];
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][sum];
}
int main(){
    vector<int> coins={1,2,5};
    int sum=11;
    cout<<change(coins,sum);
}