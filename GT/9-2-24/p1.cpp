//Write a program find the shortest path between source and destination using dijkstra's algorithm

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> graph;

public:
    Graph(int vertices) {
        V = vertices;
        graph.resize(V, vector<int>(V, 0));
    }

    void addEdge(int src, int dest, int weight) {
        graph[src][dest] = weight;
        graph[dest][src] = weight; 
    }

    int minDistance(vector<int>& dist, vector<bool>& sptSet) {
        int minDist = INT_MAX, minIndex = -1;

        for (int v = 0; v < V; ++v)
            if (!sptSet[v] && dist[v] <= minDist)
                minDist = dist[v], minIndex = v;

        return minIndex;
    }

    int dijkstra(int src, int dest) {
        vector<int> dist(V, INT_MAX);
        vector<bool> sptSet(V, false);
        vector<int> pred(V, -1); 

        dist[src] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = minDistance(dist, sptSet);

            sptSet[u] = true;

            for (int v = 0; v < V; ++v) {
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    pred[v] = u; 
                }
            }
        }

        cout << "Shortest path from " << src << " to " << dest << " is: ";
        printShortestPath(src, dest, pred);
        cout << endl;

        return dist[dest];
    }

    void printShortestPath(int src, int dest, vector<int>& pred) {
        if (src == dest)
            cout << src << " ";
        else if (pred[dest] == -1)
            cout << "No path exists";
        else {
            printShortestPath(src, pred[dest], pred);
            cout << dest << " ";
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter the edges (source -> dest.-> weight):\n";
    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    int source, destination;
    cout << "Enter source and destination vertices: ";
    cin >> source >> destination;

    int shortestDistance = g.dijkstra(source, destination);
    cout << "The shortest distance from " << source << " to " << destination << " is " << shortestDistance << endl;

    return 0;
}
