/*You are given a group of islands, and your task is to build bridges between them with the minimum possible cost so that all islands are connected. 
Each bridge connects two islands, and it has a certain cost to construct. Your objective is to find the minimum total cost required to ensure that every island is connected 
to at least one other island, either directly or indirectly.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class Graph{
    int n;
    //bool dir;
    vector<vector<int>> adjmat;
    public:
    vector<int> inMST,value,parent;
    Graph(int n){
      this->n=n;
      //dir=d;
      adjmat=vector<vector<int>> (n,vector<int> (n,0));
      inMST=vector<int>(n,1);
      value=vector<int>(n,INT16_MAX);
      parent=vector<int>(n,-1);
    }
    void addEdge(int u,int v,int w){
        adjmat[u][v]=w;
        adjmat[v][u]=w;
    }
    int mini(){
        int x=INT16_MAX; int idx= -1;
        for(int i=0;i<n;i++){
            if(inMST[i] && value[i] < x){
                x=value[i];
                idx=i;
            }
        }
        return idx;
    }
    void MST(int src){
        value[src]=0;
        parent[src]= -1;

        for(int i=0;i<n;i++){
            int u=mini();
            inMST[u]=0;
            for(int v=0;v<n;v++){
                if(inMST[v]==1 && adjmat[u][v]!=0 &&adjmat[u][v] < value[v]){
                    value[v]=adjmat[u][v];
                    parent[v]=u;
                }
            }
        }
        int cost=0;
        for(int i=0;i<n;i++){
            cost+=value[i];
        }
        cout<<"Min cost of connect islands: "<<cost<<endl;
        cout<<"The following bridge should be built: "<<endl;
        for(int i=0;i<n;i++){
            if(parent[i]!= -1)
            cout<<char(parent[i]+'A')<<"->"<<char(i+'A')<<" "<<adjmat[i][parent[i]]<<endl;
        }
    }
};
int main(){
   Graph g(6);    //A=0,B=1,C=2,D=3,E=4,F=5
   g.addEdge(0,1,3); //A-B
   g.addEdge(0,2,7); //A-C
   g.addEdge(0,3,6); //A-D
   g.addEdge(0,5,8); //A-F
   g.addEdge(1,3,7); //B-D
   g.addEdge(1,4,5); //B-E
   g.addEdge(1,5,7); //B-F
   g.addEdge(2,4,3); //C-E
   g.addEdge(2,3,2); //C-D
   g.addEdge(3,4,1); //D-E
   g.addEdge(4,5,4); //E-F

   g.MST(0);

}
