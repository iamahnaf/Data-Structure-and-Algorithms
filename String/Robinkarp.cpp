#include<bits/stdc++.h>
using namespace std;
int prime=101;
long long calculateHash(string str){
  long long hash=0;
  for(int i=0;i<str.size();i++){
   hash= hash+ str[i] * pow(prime,i);
  }
  return hash;
}
long long updateHash(long long prev,char old,char New,int patternLen){
   long long newHash= (prev- old) / prime;
   newHash=newHash + New * pow(prime,patternLen-1);
    return newHash;
}
void match(string text,string pattern){
    int n=pattern.size(); int m=text.size();
    long long patternHash=calculateHash(pattern);
    long long textHash=calculateHash(text.substr(0,n));

    for(int i=0;i<=m-n;i++){
        if(patternHash==textHash){
            if(text.substr(i,n)==pattern){
            cout<<"matched at "<<i<<endl;
            }
        }
       if (i < m - n) {
            textHash = updateHash(textHash, text[i], text[i + n], n);
        }

    }
}
int main(){
    string p="sub";
    string t="substrsubLuringsub";
    match(t,p);
   
}
