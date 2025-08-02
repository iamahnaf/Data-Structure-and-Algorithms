#include<bits/stdc++.h>
using namespace std;
int main(){
   string s="a"; int k=5;
        while(k>=s.size()){
            string x="";
            for(int i=0;i<s.size();i++){
                if(s[i]=='z') {
                    x.push_back('a');
                }
                else x.push_back((char)s[i]+1);
            }
            s+=x;
      }
        cout<<s;
}