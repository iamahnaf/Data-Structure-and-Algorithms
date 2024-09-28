#include<iostream>
using namespace std;
int febo(int n,int arr[]){
    if(n==0 || n==1) return n;
    if(arr[n]!=0){ //calculated
        return arr[n];
    }
    arr[n]=febo(n-1,arr)+febo(n-2,arr);
    return arr[n];
}
int febotab(int n){
    int dp[n+1];
    dp[0]=0; dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n=6;
    int arr[n+1]={0};
    cout<<febo(n,arr)<<endl;
    cout<<febotab(n);

}