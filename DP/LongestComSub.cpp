#include<bits/stdc++.h>
using namespace std;
int lcs(string str1,string str2,int n,int m,vector<vector<int>> dp){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    if(str1[n-1] == str2[m-1]){
        return dp[n][m]=lcs(str1,str2,n-1,m-1,dp)+1;
    }else{
        int ans1=lcs(str1,str2,n-1,m,dp);
        int ans2=lcs(str1,str2,n,m-1,dp);
        return dp[n][m]=max(ans1,ans2);
    }
}
int lcsTab(string str,string str2){
    int n=str.size(); int m=str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0;i<n+1;i++) dp[i][0]=0;
    for(int i=0;i<m+1;i++) dp[0][i]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                int ans1=dp[i-1][j];
                int ans2=dp[i][j-1];
                dp[i][j]=max(ans1,ans2);
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][m];
}
int main(){
    string one="abcde";
    string two="ace";
    int n=one.size();
    int m=two.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=0;i<n+1;i++)
    for(int j=0;j<m+1;j++){
        dp[i][j]= -1;
    }
    cout<<lcs(one,two,one.size(),two.size(),dp)<<endl;
    cout<<lcsTab(one,two);
}