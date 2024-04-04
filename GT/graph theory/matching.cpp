#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool isMatching(vector<pair<int, int>> &edges, int V)
{
    vector<bool> visited(V, false);
    for (auto &edge : edges)
    {
        if (visited[edge.first] || visited[edge.second])
            return false;
        visited[edge.first] = true;
        visited[edge.second] = true;
    }
    return true;
}
bool isMaximumMatching(vector<pair<int, int>> &edges, int V)
{
    set<int> visited;
    for (auto &edge : edges)
    {
        if (visited.find(edge.first) != visited.end() || visited.find(edge.second) != visited.end())
            return false;
        visited.insert(edge.first);
        visited.insert(edge.second);
    }
    return true;
}
bool isPerfectMatching(vector<pair<int, int>> &edges, int V)
{
    if (!isMatching(edges, V))
        return false;
    set<int> visited;
    for (auto &edge : edges)
    {
        visited.insert(edge.first);
        visited.insert(edge.second);
    }
    return visited.size() == V;
}
int main()
{
    int V, E;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;
    cout << "Enter the number of edges in the graph: ";
    cin >> E;
    vector<pair<int, int>> edges;
    cout << "Enter the edges in format 'source destination':" << endl;
    for (int i = 0; i < E; ++i)
    {
        int src, dest;
        cin >> src >> dest;
        edges.push_back({src, dest});
    }
    cout << "Enter the number of edges in the subgraph: ";
    int subE;
    cin >> subE;
    vector<pair<int, int>> subEdges;
    cout << "Enter the edges of the subgraph in format 'source destination':" << endl;
    for (int i = 0; i < subE; ++i)
    {
        int src, dest;
        cin >> src >> dest;
        subEdges.push_back({src, dest});
    }
    if (isMatching(subEdges, V))
        cout << "The subgraph is a matching." << endl;
    else
        cout << "The subgraph is not a matching." << endl;
    int maxMatchingCount = 0;
    if (isMaximumMatching(subEdges, V))
    {
        for (auto &edge : subEdges)
        {
            if (edge.first < edge.second)
                maxMatchingCount++;
        }
        cout << "Number of edges in the maximum matching: " << maxMatchingCount << endl;
    }
    else
        cout << "The subgraph is not a maximum matching." << endl;
    if (isPerfectMatching(subEdges, V))
        cout << "The subgraph is a perfect matching." << endl;
    else
        cout << "The subgraph is not a perfect matching." << endl;
    return 0;
}