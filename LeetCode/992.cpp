#include<bits/stdc++.h>
using namespace std;
int numOfSubarray(vector<int> v, int k){
    int l=0,r=0,numSubarr=0,n=v.size();
    unordered_map<int,int> hash;
                 //num,freq
    while(r<n){
        hash[v[r]]++;
        while(hash.size() > k ){
            hash[v[l]]--;
            cout<<hash[v[l]]<<" is increasing "<<endl;
            if(hash[v[l]]==0) hash.erase(v[l]);
            l++;
        }
        numSubarr=numSubarr + r - l +1;
        cout<<"sub arr no "<<numSubarr<<endl;
        r++;
    }
    return numSubarr;
}
int main(){
    vector<int> v={1,2,1,2,3};
    cout<<numOfSubarray(v,2) - numOfSubarray(v,2-1);

}