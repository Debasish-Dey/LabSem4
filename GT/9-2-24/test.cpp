#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;
void makegraph(vector<vector<pair<int, int>>> &graph){
    int e, x, y;
    cout << "No. of edges: ";
    cin >> e;
    for (int i = 0; i < e; ++i){
        cout << "Enter starting and ending vertex:";
        cin >> x >> y;
        if (x != y){
            cout << "Enter weight of this edge:";
            int weight;
            cin >> weight;
            graph[x][y] = {1, min(weight, graph[x][y].second)};
            graph[y][x] = {1, min(weight, graph[x][y].second)};
        }
    }
}
void dijkstra(vector<vector<pair<int, int>>> &graph, int start, vector<int> &distances, vector<int> &predecessors){
    int n = graph.size();
    distances.assign(n, INT_MAX);
    predecessors.assign(n, -1);
    distances[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > distances[u])  continue;
        for (int v = 0; v < n; ++v){
            if (graph[u][v].first == 1){
                int weight = graph[u][v].second;
                if (distances[v] > distances[u] + weight){
                    distances[v] = distances[u] + weight;
                    predecessors[v] = u;
                    pq.push({distances[v], v});
                }
            }
        }
    }
}
void printPath(vector<int> &predecessors, int end){
    vector<int> path;
    for (int at = end; at != -1; at = predecessors[at]) path.push_back(at);
    cout << "Path from start to end: ";
    for (int i = path.size() - 1; i >= 0; --i) cout << path[i] << " ";
    cout << endl;
}
int main(){
    int v;
    cout << "No. of vertices: ";
    cin >> v;
    vector<vector<pair<int, int>>> graph(v, vector<pair<int, int>>(v, {0, INT_MAX}));
    makegraph(graph);
    int start, end;
    cout << "Enter the start vertex: ";
    cin >> start;
    cout << "Enter the end vertex: ";
    cin >> end;
    vector<int> distances;
    vector<int> predecessors;
    dijkstra(graph, start, distances, predecessors);
    if (distances[end] == INT_MAX) cout << "There is no path from " << start << " to " << end << endl;
    else{
        cout << "Shortest distance from " << start << " to " << end << " is: " << distances[end] << endl;
        printPath(predecessors, end);
    }
}