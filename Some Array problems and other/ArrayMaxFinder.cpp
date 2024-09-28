#include<iostream>
using namespace std;
int max1D(int arr[],int n){// 1D array
   if(n==0) return arr[0];

   return max(arr[n],max1D(arr,n-1));
}
int max2D(int arr[][3],int i,int j){ //2D array
  if(i==0 && j==0)return arr[0][0];

  if(i==0)return max(max2D(arr,i,j-1),arr[i][j]);

  if(j==0)return max(max2D(arr,i-1,j),arr[i][j]);

  return max( max(max2D(arr,i-1,j),max2D(arr,i,j-1)),arr[i][j] );
}
int main(){
  int arr[]={5,8,1,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  cout<<max1D(arr,n-1)<<endl;

  int ar[3][3]={{1,2,3},{4,5,6},{7,8,9}};
  int a=sizeof(ar)/sizeof(ar[0][0]);
  int ans=max2D(ar,2,2);
  cout<<ans;
}