#include <bits/stdc++.h>
using namespace std;
void makeGraph(vector<vector<int>> &graph){
    int e1, x, y;
    cout << "No. of edges for graph: ";
    cin >> e1;
    for (int i = 0; i < e1; ++i){
        cin >> x >> y;
        if (x != y) graph[x][y] = graph[y][x] = 1;
    }
}
int main(){
    int v1;
    cout << "No. of vertices for graph: ";
    cin >> v1;
    vector<vector<int>> graph(v1, vector<int>(v1, 0));
    makeGraph(graph);
    for (int i = 0; i < v1; i++){
        int count = 0;
        for (int j = 0; j < v1; j++){
            if (graph[i][j] == 1) count++;
        }
        if (count % 2){
            cout << "Degree of each vertex is not even\n";
            cout << "Eulerian graph is not possible \n";
            return 0;
        }
    }
    cout << "Eulerian graph is  possible \n";
    return 0;
}