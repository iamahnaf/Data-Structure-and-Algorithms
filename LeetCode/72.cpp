#include<bits/stdc++.h>
using namespace std;
int editDistance(string s1,string s2,int n,int m,vector<vector<int>> &dp){ //horse ros
    
     if(n==0) return m;
     if(m==0) return n;
     if(dp[n][m]!= -1){
        return dp[n][m];
     }

     if(s1[n-1] == s2[m-1]){
        dp[n][m] = editDistance(s1,s2,n-1,m-1,dp);
     }else{
     int add=editDistance(s1,s2,n,m-1,dp)+1;
     int del=editDistance(s1,s2,n-1,m,dp)+1;
     int rep=editDistance(s1,s2,n-1,m-1,dp)+1;
     dp[n][m]=min({add,del,rep});
     }
     return dp[n][m];
}
int main(){
   string s1="intention";
   string s2="execution";
   int n=s1.size(),m=s2.size();
   vector<vector<int>> dp(n+1,vector<int>(m+1, -1));
   cout<<editDistance(s1,s2,n,m,dp);
}