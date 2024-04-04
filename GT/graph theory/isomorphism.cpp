#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>
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

void checkisomorphism(Graph *graph2 , Graph *graph , int n ){

    vector<int>degree1(n);
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
        degree1[i]=s.size();
    }
    sort(degree1.begin(),degree1.end());

    vector<int>degree2(n);
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> s;
        node *temp = graph2->adj[i];
        while (graph2->adj[i] != NULL)
        {
            if (graph2->adj[i]->data != i)
                s.insert(graph2->adj[i]->data);
            graph2->adj[i] = graph2->adj[i]->next;
        }
        graph2->adj[i] = temp;
        degree2[i]=s.size();
        
    }
    sort(degree2.begin(),degree2.end());

    for(int i=0;i<n;i++){
        cout<<degree1[i]<<" "<<degree2[i];
    }

    if(degree1==degree2) cout<<"Isomorphism";
    else cout<<"NOt isomorphism";
}

int main()
{
    int n;
    cout << "Enter the number of nodes in your graph:";
    cin >> n;
    Graph *graph = creategraph(n);
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

    int n2;
    cout << "Enter the number of nodes in second graph:";
    cin >> n2;
    Graph *graph2 = creategraph(n2);
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
            if (s > 0 && s <= n2 && e > 0 && e <= n2)
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

    if(n==n2)
    checkisomorphism(graph2,graph,n);
    else cout<<"NOt isomorphism"; 
}