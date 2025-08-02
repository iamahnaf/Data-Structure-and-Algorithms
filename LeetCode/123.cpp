#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices){ 

    if(prices.size()<2){
        return 0;
    }
    int n=prices.size();
     vector<int> left(n);
     vector<int> right(n);
     int maxProfit=INT_MIN;
     int minPrice=INT_MAX;

     for(int i=0;i<n;i++){
        minPrice=min(minPrice,prices[i]);
        maxProfit=max(maxProfit,prices[i]-minPrice);
        left[i]=maxProfit;
     }
     maxProfit=INT_MIN;
     int maxPrice=INT_MIN;
     for(int i=n-1;i>=0;i--){
          maxPrice=max(maxPrice,prices[i]);
          maxProfit=max(maxProfit,maxPrice-prices[i]);
          right[i]=maxProfit;
     }
     int maxi=0;
     for(int i=0;i<n;i++){
        maxi=max(maxi,left[i]+right[i]);
     }
     return maxi;
}
int main(){
    vector<int> arr={3,3,5,0,0,3,1,4};
    cout<<maxProfit(arr);
}