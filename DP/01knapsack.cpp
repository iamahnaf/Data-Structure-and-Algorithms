#include<iostream>
#include<vector>
using namespace std;
int knapsack(int val[],int wt[],int w,int n){ //recurssion
   if(n==0 || w==0){
    return 0;
   }
   // 
   if(wt[n-1] <= w){//valid
     //include
     int left=val[n-1]+knapsack(val,wt,w-wt[n-1],n-1);
     int right=knapsack(val,wt,w,n-1);
     return max(left,right);
   }else{
    return knapsack(val,wt,w,n-1);
   }
}
int knapsackmemo(int val[],int wt[],int w,int n,vector<vector<int>> &dp){ //recurssion
   if(n==0 || w==0){
    return 0;
   }
   // 
   if(dp[n][w] != -1){
    return dp[n][w];
   }
   if(wt[n-1] <= w){//valid
     //include
     int left=val[n-1]+knapsackmemo(val,wt,w-wt[n-1],n-1,dp);
     int right=knapsackmemo(val,wt,w,n-1,dp);
     dp[n][w]=max(left,right);
     return dp[n][w];
   }else{
    dp[n][w]=knapsackmemo(val,wt,w,n-1,dp);
    return dp[n][w];
   }
}
void print2d(vector<vector<int>> dp){
  for(int i=0;i<dp.size();i++){
    for(int j=0;j<dp[i].size();j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }
}
int knapsackTab(vector<int> val,vector<int> wt,int w){
    int n=val.size();
    vector<vector<int>> dp(n+1,vector<int>(w+1));
    for(int i=0;i<dp.size();i++){
      dp[i][0]=0;
    }
    for(int j=0;j<dp[0].size();j++){
      dp[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
      for(int j=0;j<w+1;j++){
        int v=val[i-1];
        int we=wt[i-1];
        if(we <= j){
          int incProfit=v+dp[i-1][j-we];
          int excProfit=dp[i-1][j];
          dp[i][j]=max(incProfit,excProfit);
        } else{
             dp[i][j]=dp[i-1][j];    
        }
      }
    }
    print2d(dp);
    return dp[n][w];
    //print2d(dp);
}

int main(){
    vector<int> vale={15,14,10,45,30};
    vector<int> wte={2,5,1,3,4};
    int w=7;
    cout<<knapsackTab(vale,wte,w)<<endl;
}