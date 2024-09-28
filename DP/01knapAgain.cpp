#include<iostream>
#include<vector>
using namespace std;
int knap(int val[],int wt[],int w,int n){
    if(n==0 || w==0){
        return 0;
    }
    if(wt[n-1] <= w){
        //include
        int left=val[n-1]+knap(val,wt,w-wt[n-1],n-1);
        int right=knap(val,wt,w,n-1);
        return max(left,right);
    }else{
        return knap(val,wt,w,n-1);
    }
}
int knapmemo(int val[],int wt[],int w,int n,vector<vector<int>> dp){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    if(wt[n-1] <= w){
        //include
        int left=val[n-1]+knap(val,wt,w-wt[n-1],n-1);
        int right=knap(val,wt,w,n-1);
        dp[n][w]=max(left,right);
        return dp[n][w];
    }else{
        dp[n][w]=knap(val,wt,w,n-1);
        return dp[n][w];
    }
}
int knaptab(int val[],int wt[],int n,int w){
    vector<vector<int>> dp(n+1,vector<int>(w+1));
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
     for(int i=0;i<w+1;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(wt[i-1] <= j){
                //include
                int incProfit=val[i-1]+dp[i-1][j-wt[i-1]];
                int excpProfit=dp[i-1][j];
                dp[i][j]=max(incProfit,excpProfit);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main(){
    int val[]={15,14,10,45,30};
    int wt[]={2,5,1,3,4};
    int w=7;
    vector<vector<int>> dp(5+1,vector<int>(w+1));
    for(int i=0;i<5+1;i++){
        for(int j=0;j<w+1;j++){
            dp[i][j]= -1;
        }
    }
    cout<<knaptab(val,wt,w,5);
}