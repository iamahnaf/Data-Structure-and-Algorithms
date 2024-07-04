#include<iostream>
#include<vector>
using namespace std;
 int maxSubArray(vector<int>& v) {
    int sum=0; int max=INT32_MIN;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            if(sum>max){
                max=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return max;
}
