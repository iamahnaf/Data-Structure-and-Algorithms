#include<bits/stdc++.h>
using namespace std;
long long onlynum(string s){ 
    string num=""; bool negFlag=false, numberInput=false;
    long long newnum=0;
    long long i=0;
    for(char it : s){
        i++;
        if(isspace(it)){
            continue;
        } 
    }
    for(char it:s){   //  -32abds233 1234-cdf12
        if(!isdigit(it) && !isspace(it)){
            if(isalpha(it)){
                cout<<"it is a letter: "<<it<<endl;
                if(numberInput==true){
                    return stoll(num);
                }
                if(numberInput==false){
                    return 0;
                }
            }
        }
       if(numberInput==false){
          if(isdigit(it)){
            cout<<"Number input fallse cmnd"<<endl;
             num=num+it;
             numberInput=true;   
          }
          if(it=='-'){
            negFlag=true;
        } 
       }
       else if(numberInput==true){
        cout<<"Number input true cmnd"<<endl;
           if(!isdigit(it)){
              break;
           }else{
            num=num+it;
           }
       }
   }
   if (!negFlag && newnum >= INT_MAX) return INT_MAX;
   if ( negFlag && -newnum <= INT_MIN) return INT_MIN;
   //cout<<"FInal num: "<<num<<endl;
   if(negFlag==true){
        newnum=stoi(num);
       newnum= 0-newnum;
       return newnum;
   }
   else{
    return stoll(num);
   }
}
int main(){
    string s="-91283472332";
   cout<<onlynum(s);
}