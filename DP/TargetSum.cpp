#include<bits/stdc++.h>
using namespace std;

void print(bool dp[][11], int n, int sum) {
   for(int i = 0; i <= n; i++) {
       for(int j = 0; j <= sum; j++) {
           if(dp[i][j]) 
               cout << "true  ";
           else 
               cout << "false ";
       }
       cout << endl;
   }
}

bool targetSumSubset(int arr[], int sum, int n) {
   bool dp[n+1][sum+1];

   for(int i = 0; i <= n; i++) {
       dp[i][0] = true;
   }
   for(int i = 1; i <= sum; i++) {
      dp[0][i] = false;
   }

   for(int i = 1; i <= n; i++) {
       for (int j = 1; j <= sum; j++) {
           int v = arr[i-1];
           if (v <= j) {
               dp[i][j] = dp[i-1][j] || dp[i-1][j-v];
           } else {
               dp[i][j] = dp[i-1][j];
           }
       }
   }

   // Debugging output to verify the final values of dp array
  

   return dp[n][sum];
}

int main() {
    int arr[] = {4, 2, 7, 1, 3};
    int sum = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    bool ans = targetSumSubset(arr, sum, n);
    if(ans) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
