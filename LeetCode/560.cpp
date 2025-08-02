#include<bits/stdc++.h>
using namespace std;
int numberOfSubArray(vector<int> v,int k){
    int prefixsum=0;
    unordered_map<int,int> prefixCount; // 3 4 3 4 7
    prefixCount[0]=1;
    int count=0;
    for(auto it : v){
        prefixsum+=it;
        if(prefixCount.find(prefixsum - k) != prefixCount.end()){
             count=count+prefixCount[prefixsum - k];
             //cout<<prefixCount[prefixsum - k]<<endl;
        }
        prefixCount[prefixsum]++;
    }
    return count;
}
int main(){
  vector<int> v={3,4,3,4,7};
  cout<<numberOfSubArray(v,7);
}