#include<bits/stdc++.h>
using namespace std;
int rec(vector<vector<int>> &grid, int i,int j, vector<vector<int>> &visited){
       int n=grid.size(),m=grid[0].size();
    if(i < 0 || j < 0 || i>=n || j>=m ||grid[i][j]==0 || visited[i][j]==1 ){
        return 0;
    } 
    visited[i][j]=1;
    int ans=0;
    //left
    
     ans=max(ans,rec(grid,i,j-1,visited)+grid[i][j]);
    //right
 
     ans=max(ans,rec(grid,i,j+1,visited)+grid[i][j]);

    //up
  
    ans=max(ans,rec(grid,i-1,j,visited)+grid[i][j]);

    //down
  
     ans=max(ans,rec(grid,i+1,j,visited)+grid[i][j]);
    
    visited[i][j]=0;
    return ans;
}
int getmaxgold(vector<vector<int>> grid){
    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0)); int gold=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j< grid[i].size();j++){
           if (grid[i][j] != 0) {
                gold = max(gold, rec(grid, i, j, visited));
            }
        }
    }
    return gold;
}
int main(){
      vector<vector<int>> v={{0,6,0},{5,8,7},{0,9,0}};
      cout<<getmaxgold(v);
}