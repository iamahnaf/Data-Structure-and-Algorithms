#include<bits/stdc++.h>
using namespace std;
uint32_t reverseBits(int n){
     uint32_t res=0;
     for(int i=0; i < 32 ; i++){
        res=res << 1;  // left shift 1-> 10
        res= res + (n & 1); //adding the the last digit 1 or not in the result
        n=n >> 1; // removing the last dighit by right shift like 101 -> 10
     }
     return res;
}
int main(){
   cout<<reverseBits(13);
}