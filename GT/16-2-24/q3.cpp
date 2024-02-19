// program to display the distance between 2 vertex in a graph ,eccentricity of all vertex , diameter and radius of the graph



#include <iostream>
#include <vector>

using namespace std;

void makeGraph(vector<vector<int>> &graph)
{
    int e1, x, y;
    cout << "No. of edges for graph: ";
    cin >> e1;
    for (int i = 0; i < e1; ++i)
    {
        cin >> x >> y;
        if (x != y)
        {
            graph[x][y] = 1;
            graph[y][x] = 1;
        }
    }
}

int main()
{
    int v1;
    cout << "Enter the number of vertices: ";
    cin >> v1;
    vector<vector<int>> graph(v1, vector<int>(v1, 0));
    makeGraph(graph);
    vector<int> degree(v1, 0);
    for (int i = 0; i < v1; i++)
    {
        int count = 0;
        for (int j = 0; j < v1; j++)
        {
            if (graph[i][j] == 1)
                count++;
        }
        if (count % 2)
        {
            cout << "Not a EULERIAN GRAPH \n";
            return 0;
        }
    }

    cout << "It is a EULERIAN GRAPH \n";
    return 0;
}