#include<bits/stdc++.h>
using namespace std;
int febo(int x){
    if(x<=1){
        return 1;
    }
    return febo(x-1)+febo(x-2);
}
int main(){
   cout<<febo(7);
}