#include<iostream>
using namespace std;

int partition(int* arr,int low,int high){
    int pivot=arr[high]; cout<<"pivot:"<<pivot<<endl;
    int i= low-1;
    for(int j=low;j<high;j++){
        if(arr[j] <= pivot){  
         i++;
         int temp=arr[j];
         arr[j]=arr[i];
         arr[i]=temp;
        }
    }
    i++;
    int temp=pivot;
    arr[high]=arr[i];
    arr[i]=temp;
    return i;
}
void quicksort(int* arr,int low,int high){ //024
    if(low>=high)return;
    int pvt=partition(arr,low,high);
    quicksort(arr,low,pvt-1);
    quicksort(arr,pvt+1,high);
}
int main(){
    int arr[]={8,2,1,0,4,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}