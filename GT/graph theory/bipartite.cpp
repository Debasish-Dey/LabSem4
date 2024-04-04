// check if the given graph is bipartite
#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int n;
bool isbipartite(const std::vector<std::vector<int>> &graph, int start, std::vector<int> &color){
    std::queue<int> q;
    color[start] = 0;
    q.push(start);
    while (!q.empty()){
        int c = q.front();
        q.pop();
        for (int adj = 0; adj < n; ++adj){
            if (graph[c][adj] == 1){
                if (color[adj] == -1){
                    color[adj] = 1 - color[c];
                    q.push(adj);
                }
                else if (color[adj] == color[c])  return false;
            }
        }
    }
    return true; 
}
bool check(vector<vector<int>> &graph){
    std::vector<int> color(n, -1);
    for (int i = 0; i < n; ++i){
        if (color[i] == -1 && !isbipartite(graph, i, color))  return false;
    }
    return true;
}
int main(){
    cout << "Enter the numbner of vertex in your graph:";
    cin >> n;
    vector<vector<int>> adjmat(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) adjmat[i][j]=0;
    }
    int e1, x,y;
    cout << "No. of edges for graph 1: ";
    cin >> e1;
    for (int i = 0; i < e1; ++i){
        cin >> x >> y;
        if (x != y) adjmat[x][y] =adjmat[y][x] = 1;
    }
    if(check(adjmat)) cout<<"Yes";
    else cout<<"No";
}