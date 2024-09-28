#include<iostream>
using namespace std;
pair<int,pair<int,int>> largestPair(int arr[],int idx[],int low,int high){
      int mid=(low+high)/2;
      if(low==high){
          pair<int,pair<int,int>> p;
          p.first=arr[low];
          p.second.first=idx[low];
          p.second.second=idx[low]+1;
          return p;
      }
      auto left=largestPair(arr,idx,low,mid);
      auto right=largestPair(arr,idx,mid+1,high);
      return (left.first> right.first) ? left:right;
}
pair<int,pair<int,int>> helper(int arr[],int n){
    int ar[n]; int index[n];
    for(int i=0;i<n;i++){
        ar[i]=arr[i]+arr[i+1];
        index[i]=i;
    }
     return largestPair(ar,index,0,n-1);
}
int main(){
    int arr[]={5,4,10,11,3,9};
    int n=sizeof(arr)/sizeof(arr[0]);
  auto it=helper(arr,n-1);
  cout<<it.first<<" first index: "<<it.second.first<<" second index: "<<it.second.second<<endl;
}