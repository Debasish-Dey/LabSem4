#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V);
    void addEdge(int u, int v);
    int BFS(int src);
    int edgeConnectivity();
    int vertexConnectivity();
};

Graph::Graph(int V) : V(V) {
    adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int Graph::BFS(int src) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[src] = true;
    q.push(src);
    int maxDist = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                maxDist = max(maxDist, v);
            }
        }
    }
    return maxDist;
}

int Graph::edgeConnectivity() {
    int minEdgeConnectivity = INT_MAX;
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            auto it = find(adj[u].begin(), adj[u].end(), v);
            adj[u].erase(it);
            it = find(adj[v].begin(), adj[v].end(), u);
            adj[v].erase(it);
            int maxDist = BFS(u);
            minEdgeConnectivity = min(minEdgeConnectivity, maxDist);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    return minEdgeConnectivity;
}

int Graph::vertexConnectivity() {
    int minVertexConnectivity = INT_MAX;
    vector<bool> visited(V, false);
    for (int u = 0; u < V; ++u) {
        if (!visited[u]) {
            visited[u] = true;
            vector<vector<int>> tempAdj = adj;
            tempAdj[u].clear();
            for (int v = 0; v < V; ++v) {
                auto it = find(tempAdj[v].begin(), tempAdj[v].end(), u);
                if (it != tempAdj[v].end()) {
                    tempAdj[v].erase(it);
                }
            }
            int maxDist = BFS(u);
            minVertexConnectivity = min(minVertexConnectivity, maxDist);
        }
    }
    return minVertexConnectivity;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    Graph g(V);
    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << "Edge Connectivity: " << g.edgeConnectivity() << endl;
    cout << "Vertex Connectivity: " << g.vertexConnectivity() << endl;
    return 0;
}