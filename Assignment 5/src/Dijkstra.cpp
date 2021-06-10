#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<int,int> myPair;

class Graph{
    int V;
    list<myPair> *adj;
public:
    Graph(int V);
    void addEdge(int u,int v,int w);
    void shortestPath(int src);
};
Graph::Graph(int V){
    this->V = V;
    adj = new list<myPair>[this->V];
}
void Graph::addEdge(int u,int v,int w){
    adj[u].push_back({v,w});
}
//Dijkstra
void Graph::shortestPath(int src){
    priority_queue<myPair,vector<myPair>,greater<myPair> > pq;
    vector<int> dist(this->V,INF);
    dist[src] = 0;
    list<myPair>::iterator it;

    pq.push({0,src});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(it = adj[u].begin();it!=adj[u].end();++it){
            int v = it->first;
            int w = it->second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }

    for(int i=0;i<this->V;i++){
        cout << "Distance to " << i << ":" << dist[i] << endl;
    }
}
int main(){
    int V = 5, e = 4;
    cout << "Enter vertices: ";
    cin >> V;
    cout <<  "Enter edges: ";
    cin >> e;

    Graph g(V);

    for (int i = 0; i < e; i++) {
        int a, b, w;
        cout << "Enter pair (from to weight): ";
        cin >> a >> b >> w;
        g.addEdge(a,b,w);

    }
    int src = 0;
    g.shortestPath(src);
    return 0;
}

Initialize an empty stack for storage of nodes, S.
For each vertex u, define u.visited to be false.
Push the root (first node to be visited) onto S.
While S is not empty:
    Pop the first element in S, u.
    If u.visited = false, then:
        U.visited = true
        for each unvisited neighbor w of u:
            Push w into S.
End process when all nodes have been visited.
