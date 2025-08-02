#include<bits/stdc++.h>
using namespace std;
int totalfruit(vector<int> v){
   unordered_map<int,int> m;
               // number, amount of number
    int l=0,r=0,maxfruit=0;   // 3 3 3 1 2 1 1 2 3 3 4 
    
    while(r < v.size()){
        m[v[r]]++;
        while(m.size() > 2){
            m[v[l]]--; if(m[v[l]]==0){
                m.erase(v[l]);
            }
            l++;
           //cout<<"map size more than 2 "<<v[r]<<endl;
        }
        maxfruit=max(maxfruit, r - l +1);
        r++;
        
    }
    return maxfruit;
}
int main(){
  vector<int> v={1,2,3,2,2};
  cout<<totalfruit(v);
}