#include<bits/stdc++.h>
using namespace std;
struct info{
    int low,high,sum;
};

info cross_subarry(int arr[],int low,int mid,int high){
     info cross_sub;
     int sum=0;
     int leftsum=INT32_MIN;
     for(int i=mid;i>=low;i--){
        sum=sum+arr[i];
        if(sum>leftsum){
            leftsum=sum;
            cross_sub.low=i;
        }
     }
     int rightsum=INT32_MIN;
     sum=0;
     for(int j=mid+1;j<=high;j++){
        sum=sum+arr[j];
        if(sum>rightsum){
            rightsum=sum;
            cross_sub.high=j;
        }
     }
   cross_sub.sum=leftsum+rightsum;
   return cross_sub;
}
info maximum_subarray(int arr[],int low,int high){
    
    int mid=(low+high)/2;
    if(low==high){
        info max_sub;
        max_sub.low=low;
        max_sub.high=high;
        max_sub.sum=arr[low];
        return max_sub;
    }
    info left=maximum_subarray(arr,low,mid);
    info right=maximum_subarray(arr,mid+1,high);
    info cross=cross_subarry(arr,low,mid,high);

    if(left.sum>=right.sum && left.sum>=cross.sum) return left;
    if(right.sum>=left.sum && right.sum>=cross.sum) return right;
    return cross;
}
int main(){
    int arr[]={2,1,-3,4,-1,2,1,-5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    info ans=maximum_subarray(arr,0,n-1);
    cout<<"start index: "<<ans.low<<" End index: "<<ans.high<<" SUM: "<<ans.sum<<endl;
}