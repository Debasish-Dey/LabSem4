// write a program to check weather a hamiltonian cycle or path exist in a given graph or not

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v1;
void makegraph(vector<vector<int>> &graph1){
    int e1, x, y;
    cout << "No. of edges for graph : ";
    cin >> e1;
    for (int i = 0; i < e1; ++i){
        cin >> x >> y;
        if (x != y){
            graph1[x][y] = 1;
            graph1[y][x] = 1;
        }
    }
}
bool isSafe(int v, vector<vector<int>> &graph, vector<int> &path, int pos) {
    if (graph[path[pos - 1]][v] == 0) return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)   return false;
    return true;
}
bool hamiltonianPathUtil(vector<vector<int>> &graph, vector<int> &path, int pos, int n) {
    if (pos == n)   return true;
    for (int v = 0; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianPathUtil(graph, path, pos + 1, n))  return true;
            path[pos] = -1;
        }
    }
    return false;
}
bool hamiltonianPath(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> path(n, -1);
    path[0] = 0;
    if (!hamiltonianPathUtil(graph, path, 1, n)) {
        cout << "No Hamiltonian path exists." << endl;
        return false;
    }
    cout << "Hamiltonian path exists: ";
    for (int i = 0; i < n; i++)  cout << path[i] << " ";
    cout << endl;
    return true;
}
bool isHamiltonianCycle(vector<vector<int>> &graph, vector<int> &path, int pos, int n) {
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1)   return true;
        else   return false;
    }
    for (int v = 1; v < n; v++) {
        if (graph[path[pos - 1]][v] == 1) {
            bool isVisited = false;
            for (int i = 0; i < pos; i++) {
                if (path[i] == v) {
                    isVisited = true;
                    break;
                }
            }
            if (!isVisited) {
                path[pos] = v;
                if (isHamiltonianCycle(graph, path, pos + 1, n))
                    return true;
                path[pos] = -1;
            }
        }
    }
    return false;
}
bool hamiltonianCycle(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> path(n, -1);
    path[0] = 0;
    if (!isHamiltonianCycle(graph, path, 1, n)) {
        cout << "No Hamiltonian cycle exists." << endl;
        return false;
    }
    cout << "Hamiltonian cycle exists: ";
    for (int i = 0; i < n; i++)  cout << path[i] << " ";
    cout << path[0] << endl;
    return true;
}
int main(){
    cout << "No. of vertices for graph 1: ";
    cin >> v1;
    vector<vector<int>> graph1(v1, vector<int>(v1,0));
    makegraph(graph1);
    if(hamiltonianCycle(graph1));
    else{
        hamiltonianPath(graph1);
    }
}