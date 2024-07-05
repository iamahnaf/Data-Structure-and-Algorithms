#include<iostream>
using namespace std;
int evenNumber(int arr[],int low,int high){
    int mid=(low+high)/2;
    if(low==high){
        if(arr[low]%2==0)return 1;
        return 0;
    }
    int left=evenNumber(arr,low,mid);
    int right=evenNumber(arr,mid+1,high);
    int cross=left+right;
    return cross;
}