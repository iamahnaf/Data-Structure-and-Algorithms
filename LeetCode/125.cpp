#include <cmath>
#include <cstdio>
#include <vector>
#include<string>
#include <iostream>
#include <algorithm>
//
#define sall s.begin(),s.end()
#define vall v.begin(),v.end()
using namespace std;
//

bool ispalindrome(string s){
   int left=0,right=s.size()-1; //"A man, a plan, a canal: Panama"
   while(left < right){
      while(left<right && !isalnum(s[left])) left++;
      while(left<right && !isalnum(s[right])) right++;
      if(tolower(s[left])!=tolower(s[right])){
        return false;
      }
      left++;
      right--;
   }
   return true;
}
int main(){
  string s="0p";
  ispalindrome(s);
}