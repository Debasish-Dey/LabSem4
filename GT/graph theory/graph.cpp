
#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
using namespace std;

struct node
{
    int data;
    node *next;
};

struct Graph
{
    int v;
    node **adj;
};

Graph *creategraph(int v)
{
    Graph *graph = new Graph;
    graph->v = v;
    graph->adj = new node *[v];

    for (int i = 0; i < v; i++)
        graph->adj[i] = NULL;

    return graph;
}

void addedge(Graph *graph, int u, int v)
{
    node *newnode = new node;
    newnode->data = v;
    newnode->next = graph->adj[u];
    graph->adj[u] = newnode;
}

void checkparallel(Graph *graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> s;
        int m = 0;
        node *temp = graph->adj[i];
        while (graph->adj[i] != NULL)
        {
            m++;
            s.insert(graph->adj[i]->data);
            graph->adj[i] = graph->adj[i]->next;
        }
        graph->adj[i] = temp;
        if (s.size() != m)
        {
            cout << "Parallal edge is present\n";
            return;
        }
    }
    cout << "parallel edge is not present\n";
}

void completegraph(Graph *graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> s;
        node *temp = graph->adj[i];
        while (graph->adj[i] != NULL)
        {
            if (graph->adj[i]->data != i)
                s.insert(graph->adj[i]->data);
            graph->adj[i] = graph->adj[i]->next;
        }
        graph->adj[i] = temp;
        if (s.size() != n - 1)
        {
            cout << "Not complete graph\n";
            return;
        }
    }
    cout << "Compplete graph\n";
}

int main()
{
    int n;
    cout << "Enter the number of nodes in your graph:";
    cin >> n;
    vector<int> degree(n, 0);
    Graph *graph = creategraph(n);
    int count = 0;
    int selfloop = 0;
    while (1)
    {
        cout << "Enter 1 if you ant to add more edges:";
        cout << "enter 2 if you dont want:";
        int t;
        cin >> t;
        if (t == 1)
        {
            int s, e;
            cout << "Enter starting and ending vertices:";
            cin >> s >> e;
            if (s > 0 && s <= n && e > 0 && e <= n)
            {
                count++;
                if (s == e)
                    selfloop = 1;
                degree[s - 1]++;
                degree[e - 1]++;
                addedge(graph, s - 1, e - 1);
                if (s != e)
                {
                    addedge(graph, e - 1, s - 1);
                }
            }
            else
                cout << "Invalid choice try again\n";
        }
        else
            break;
    }
    cout << "Numnber of vertices are:" << n << endl;
    cout << "Number of Edges  are" << count << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Degree of vertex " << i << "is" << degree[i] << endl;
    }
    checkparallel(graph, n);
    if (selfloop)
        cout << "Self loop is present\n";
    else
        cout << "Self loop is not present\n";
    completegraph(graph, n);
}
