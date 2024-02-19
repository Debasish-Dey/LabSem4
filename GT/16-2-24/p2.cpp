#include <iostream>
#include <vector>
#include <queue>
#include<limits.h>
#include <algorithm>
using namespace std;
const int INF = 1e9;

vector<int> shortestDistances(int source, const vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> distances(n, INF);
    distances[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] && distances[v] == INF)
            {
                distances[v] = distances[u] + 1;
                q.push(v);
            }
        }
    }
    return distances;
}

int distanceBetweenVertices(int u, int v, const vector<vector<int>> &graph)
{
    vector<int> distances = shortestDistances(u, graph);
    return distances[v];
}

void find(vector<int> &ecentricity,int & radius,int & diameter){
    for(auto it:ecentricity){
        radius=min(radius,it);
        diameter=max(diameter,it);
    }
}

int main()
{
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>>d(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int distUV = distanceBetweenVertices(i, j, graph);
            d[i][j]=distUV;
        }
    }
    cout<<"\nDistance of one vertex to another is :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }

    cout << "\nEccentricity of vertices are:\n";
    vector<int>e;
    for (int i = 0; i < n; ++i)
    {
        int ans=0;
        for(int j=0;j<n;j++){
            ans=max(ans,d[i][j]);
        }
        e.push_back(ans);
    }
    for(int i=0;i<n;i++){
        cout<<e[i]<<endl;
    }
    int radius=INT_MAX;
    int diameter=INT_MIN;
    find(e,radius,diameter);
    cout<<"\nRadius of the given graph is :"<<radius<<endl;
    cout<<"\nDiameter of the given graphg is :"<<diameter<<endl;
    return 0;
}