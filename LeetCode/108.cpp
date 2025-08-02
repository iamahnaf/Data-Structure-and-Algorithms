#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
TreeNode *divide(vector<int> v,int left, int right){
     if(left> right) return nullptr;
     int mid=(left+right)/2;
     TreeNode *root=new TreeNode(v[mid]);
     root->left=divide(v,left,mid-1);
     root->right=divide(v,mid+1,right);
     return root;
 }
TreeNode * toBST(vector<int> v){
    return divide(v,0,v.size()-1);
  }
int main(){

}