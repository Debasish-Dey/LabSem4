// #include <iostream>
// #include <list>
// #include <vector>
// #include <xutility>

#include<bits/stdc++.h>

using namespace std;

class Graph {
private:
    int V; 
    vector<list<int>> adjList;

public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    int getNumVertices() const {
        return V;
    }

    int getNumEdges() const {
        int edges = 0;
        for (int i = 0; i < V; ++i) {
            edges += adjList[i].size();
        }
        return edges / 2; 
    }

    int getDegree(int v) const {
        return adjList[v].size();
    }

    bool hasSelfLoop() const {
        for (int i = 0; i < V; ++i) {
            for (int neighbor : adjList[i]) {
                if (i == neighbor) {
                    return true;
                }
            }
        }
        return false;
    }

    bool hasParallelEdges() const {
        vector<vector<bool>> edgeMatrix(V, vector<bool>(V, false));

        for (int i = 0; i < V; ++i) {
            for (int neighbor : adjList[i]) {
                if (edgeMatrix[i][neighbor]) {
                    return true;
                }
                edgeMatrix[i][neighbor] = true;
                edgeMatrix[neighbor][i] = true;
            }
        }
        return false;
    }

    bool isCompleteGraph() {
        for (int i = 0; i < V; ++i) {
            for (int j = i + 1; j < V; ++j) {
                if (find(adjList[i].begin(), adjList[i].end(), j) == adjList[i].end() &&
                    find(adjList[j].begin(), adjList[j].end(), i) == adjList[j].end()) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int numVertices, numEdges;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    Graph g(numVertices);

    cout << "Enter the edges (vertex1 vertex2):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        g.addEdge(vertex1, vertex2);
    }

    cout << "\nNumber of Vertices: " << g.getNumVertices() << endl;
    cout << "Number of Edges: " << g.getNumEdges() << endl;

    for (int i = 0; i < g.getNumVertices(); ++i) {
        cout << "Degree of Vertex " << i << ": " << g.getDegree(i) << endl;
    }

    cout << "Has Self Loop: " << (g.hasSelfLoop() ? "Yes" : "No") << endl;
    cout << "Has Parallel Edges: " << (g.hasParallelEdges() ? "Yes" : "No") << endl;
    cout << "Is Complete Graph: " << (g.isCompleteGraph() ? "Yes" : "No") << endl;

    return 0;
}
