/*Mr. Chandler has recently introduced a Home Delivery service at one of his restaurants. Since the service is new, he only employs one delivery person. However, there’s a problem—this delivery boy tends to be forgetful!

Every time the delivery boy is sent out for delivery, he forgets to fill up the fuel tank of his scooter beforehand. So, each time Mr. Chandler assigns him a delivery, the boy first stops at the gas station, gets fuel, and then continues to the delivery location. He follows this routine every single time, no matter where the destination is.

To try and deliver the food as quickly as possible, the delivery boy always chooses the shortest path (in terms of time) between the restaurant and the gas station, and then from the gas station to the delivery location.

Your task is to help Mr. Chandler figure out how much time the delivery boy could save if he had enough fuel to go directly from the restaurant to the delivery destination without stopping at the gas station. The city has N streets, numbered from 0 to N-1. The restaurant is on street S, the gas station is on street G, and the food has to be delivered to street D. It’s possible that S, G, and D might all be the same or different.


Now do the followings:
•	Create a class Graph

•	Declare an adjacency matrix adjMat

•	Write a function “addEdge(u,v,w)” : which sets adjMat[u][v] = w and adjMat[v][u] = w. This represents the time to travel from street u to street v is w.

•	Write a function findPath(S, D): which finds the minimum time required to travel from S(restaurant) to D(Delivery location) and also prints the path.

•	Write a function findPath(S, G, D): which finds the minimum time required to travel from S(restaurant) to G(Gas station) and then G(Gas station) to D(Delivery location) and also prints the path.

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
    Graph(int n){
      this->n=n;
      //dir=d;
      adjmat=vector<vector<int>> (n,vector<int> (n,0));
    }
    void addEdge(int u,int v,int w){
        adjmat[u][v]=w;
        adjmat[v][u]=w;
    }
    void findpath(int s,int d){  
        vector<int> dist(n,INT16_MAX);
        vector<int> parent(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        dist[s]=0;
        parent[s]= -1;
        pq.push({0,s});
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            //
            for(int v=0;v<n;v++){
                if(adjmat[u][v]){
                    int wt=adjmat[u][v];
                    if(dist[v] > dist[u]+wt){
                        dist[v]=dist[u]+wt;
                        pq.push({dist[v],v});
                        parent[v]=u;
                    }
                }
            }
        }
        //print 
         cout<<"Min distanc: "<<dist[d]<<endl;
        int i=d;
        stack<int> stk;
        while(i!= -1){
            stk.push(i);
            i=parent[i];
        }
        while(!stk.empty()){
            int x=stk.top();
            cout<<x;
            stk.pop();
            if(!stk.empty()) cout<<"-> ";
        }
    
    }
     void findpath(int s, int g, int d) {
        // First part: find min path from s to g
        vector<int> dist(n, INT16_MAX);
        vector<int> parent(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[s] = 0;
        parent[s] = -1;
        pq.push({0, s});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            for (int v = 0; v < n; v++) {
                if (adjmat[u][v]) {
                    int wt = adjmat[u][v];
                    if (dist[v] > dist[u] + wt) {
                        dist[v] = dist[u] + wt;
                        pq.push({dist[v], v});
                        parent[v] = u;
                    }
                }
            }
        }
        cout << "Min distance from " << s << " to " << g << ": " << dist[g] << endl;
        int maxdist = dist[g];
        int i = g;
        stack<int> stk;

        while (i != -1) {
            stk.push(i);
            i = parent[i];
        }
        while (!stk.empty()) {
            int x = stk.top();
            cout << x;
            stk.pop();
            if (!stk.empty()) cout << " -> ";
        }
        cout << endl;

        // Second part
        vector<int> dist2(n, INT16_MAX);
        vector<int> parent2(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        dist2[g] = 0;
        parent2[g] = -1;
        pq2.push({0, g});

        while (!pq2.empty()) {
            int u = pq2.top().second;
            pq2.pop();
            
            for (int v = 0; v < n; v++) {
                if (adjmat[u][v]) {
                    int wt = adjmat[u][v];
                    if (dist2[v] > dist2[u] + wt) {
                        dist2[v] = dist2[u] + wt;
                        pq2.push({dist2[v], v});
                        parent2[v] = u;
                    }
                }
            }
        }

        maxdist = maxdist + dist2[d];
        cout<< "Min distnce from "<<g<<" to "<<d<<": "<< dist2[d]<<endl;
        cout<<"Total distance from "<<s<<" -> "<<g<<" -> "<<d<<": "<<maxdist<<endl;

        // Print the second part
        i = d;
        stack<int> stk2;
        while (i != -1) {
            stk2.push(i);
            i = parent2[i];
        }
        while (!stk2.empty()) {
            int x = stk2.top();
            cout << x;
            stk2.pop();
            if (!stk2.empty()) cout << " -> ";
        }
        cout << endl;
    }
};
int main(){
    Graph g(9);
    g.addEdge(0,1,2);
    g.addEdge(0,2,9);
    g.addEdge(0,6,4);
    g.addEdge(0,3,2);
    g.addEdge(0,5,8);
    g.addEdge(2,1,5);
    g.addEdge(2,7,1);
    g.addEdge(1,5,3);
    g.addEdge(7,5,6);
    g.addEdge(7,8,3);
    g.addEdge(5,1,3);
    g.addEdge(5,8,2);
    g.addEdge(8,4,2);
    g.addEdge(8,6,1);
    g.addEdge(3,4,1);
    //g.findpath(0,7);
    g.findpath(0,5,7);
}