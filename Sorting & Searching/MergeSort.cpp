#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void merge(vector<int> &arr,int low,int mid,int high){
    int i=low;
    int j=mid+1;
    int idx=low; vector<int> temp(arr.size());
    while(i<=mid && j<=high){
        if(arr[i]<=arr[j]){
            temp[idx++]=arr[i];
            i++;
        }else{
            temp[idx++]=arr[j];
            j++;
        }
    }
    while(i<=mid){
        temp[idx++]=arr[i++];
    }
    while(j<=high){
        temp[idx++]=arr[j++];
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i];
    }
}
void mergeSort(vector<int> &arr,int low,int high){
    if(low==high){
        return;
    }
    int mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    vector<int> v={5,1,3,0,11,9,3,2};
    int n=v.size();
    mergeSort(v,0,n-1);
   
     for(auto it:v){
        cout<<it<<" ";
     }
}
