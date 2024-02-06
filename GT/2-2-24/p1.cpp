#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
#include<set>
#include<algorithm>
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


void checkunion(Graph *g1, Graph *g2, int n){
    Graph *g = creategraph(n);
    for(int i=0; i<n; i++){
        set<int> s;
        while (g1->adj[i] != NULL)
        {
            if (g1->adj[i]->data != i)
                s.insert(g1->adj[i]->data);
            g1->adj[i] = g1->adj[i]->next;
        }
        while (g2->adj[i] != NULL)
        {
            if (g2->adj[i]->data != i)
                s.insert(g2->adj[i]->data);
            g2->adj[i] = g2->adj[i]->next;
        }
        for(int j : s){
            addedge(g, i, j);
        }
    }
}

void print_graph(Graph *graph, int n){
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        while (graph->adj[i] != NULL)
        {
            if (graph->adj[i]->data != i)
                a[i][graph->adj[i]->data]=1;
            graph->adj[i] = graph->adj[i]->next;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of nodes in your graph:";
    cin >> n;
    Graph *graph = creategraph(n);
    while (1)
    {
        cout << "Enter 1 to add more edges"<<endl;
        cout << "Enter 2 to stop "<<endl;
        int t;
        cin >> t;
        if (t == 1)
        {
            int s, e;
            cout << "Enter starting and ending vertices:";
            cin >> s >> e;
            if (s > 0 && s <= n && e > 0 && e <= n)
            {
                if (s != e)
                {
                    addedge(graph, e - 1, s - 1);
                    addedge(graph, s - 1, e - 1);
                }
            }
            else
                cout << "Invalid choice try again\n";
        }
        else
            break;
    }

    Graph *graph2 = creategraph(n);
    while (1)
    {
        cout << "Enter 1 to add more edges:"<<endl;
        cout << "Enter 2 to stop "<<endl;
        int t;
        cin >> t;
        if (t == 1)
        {
            int s, e;
            cout << "Enter starting and ending vertices:";
            cin >> s >> e;
            if (s > 0 && s <= n && e > 0 && e <= n)
            {
                if (s != e )
                {
                    addedge(graph2, e - 1, s - 1);
                    addedge(graph2, s - 1, e - 1);
                }
            }
            else
                cout << "Invalid choice try again\n";
        }
        else
            break;
    }

    checkunion(graph, graph2, n);
}