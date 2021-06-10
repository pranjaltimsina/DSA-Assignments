// Exp 5B: DFS
// Author: Pranjal Timsina; 20BDS0392
#include <iostream>
#include <vector>
using namespace std;

class Graph {

    int v, e; // vertices, edges
    int** adj; // Adjacency matrix

public:
    Graph(int v, int e); // constructor

    void addEdge(int start, int e); // insert new edge

    // dfs traversal
    void DFS(int start, vector<bool>& visited, Graph T);

    void printMatrix() {
        for (int row = 0; row < v; row++) {
            cout << "\n";
            for (int c= 0;c< v;c++) {
                cout << adj[row][c] << " ";
            }
        }
    }
};

// Function to fill the empty adjacency matrix
Graph::Graph(int v, int e) {
    // fill adjacency matrix
    this->v = v;
    this->e = e;
    adj = new int*[v];
    for (int row = 0; row < v; row++) {
        adj[row] = new int[v];
        for (int column = 0; column < v; column++) {
            adj[row][column] = 0;
        }
    }
}

void Graph::addEdge(int start, int e) {
    // add an edge to the graph
    adj[start][e] = 1;
}

// Function to perform DFS on the graph
void Graph::DFS(int start, vector<bool>& visited, Graph T) {

    visited[start] = true;

    for (int i = 0; i < v; i++) {
        // go to the depths of a node
        if (adj[start][i] == 1 && (!visited[i])) {
            T.addEdge(start, i);
            DFS(i, visited, T);
        }
    }
}

// Driver code
int main()
{
    int v = 5, e = 4;
    cout << "Enter vertices: ";
    cin >> v;
    cout <<  "Enter edges: ";
    cin >> e;

    Graph G(v, e);
    Graph T(v, e);
    for (int i = 0; i < e; i++) {
        int a, b;
        cout << "Enter pair (0 1): ";
        cin >> a >> b;
        G.addEdge(a, b);

    }
    vector<bool> visited(v, false);

    G.DFS(0, visited, T);
    T.printMatrix();
}
