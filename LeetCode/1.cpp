#include<bits/stdc++.h>
#include<iterator>
using namespace std;
vector<int> twosum(vector<int> v, int target){
    unordered_map<int,int> hash;
    for(int i=0;i<v.size();i++){
        hash[v[i]]=i;
    }
    for(int it=0;it<v.size();it++){
        int diff=target-v[it];
        if(hash.find(diff)!=hash.end() && hash[diff] != it){
            return {it,hash[diff]};
        }
    }
    return {};
}
int main(){
   vector<int> v={3,2,4};
   vector<int> it=twosum(v,6);
   for(auto i: it){
    cout<<i;
   }
}