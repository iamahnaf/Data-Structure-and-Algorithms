#include<bits/stdc++.h>
using namespace std;
long long onlynum(string s){
    bool negflag=false, numInput=false;
    int i=0;
    long long ans=0;
    for(char c: s){
        if(isspace(c)) i++;
        if(!isspace(c)) break;
    }
    // neg checking
    if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
        negflag = (s[i] == '-');
        i++;
    }
    //
    while(i<s.length()){
        char it=s[i];
        if(!isdigit(it)){
            break;
        }
        cout<<"its a digit"<<it<<endl;
        numInput=true;
        int digit=it-'0';
        if (!negflag && (ans > (INT_MAX - digit) / 10)) {
            return INT_MAX;
        }
        if (negflag && (-ans < (INT_MIN + digit) / 10)) {
            return INT_MIN;
        }

        ans= ans*10+digit;
        i++;
    }
    return negflag ? -ans : ans;
}
int main(){
    string s="-+12";
    cout<<onlynum(s);

}