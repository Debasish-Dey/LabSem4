#include <iostream>
#include <list>
#include <set>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Graph
{
    int v;
    Node **adj;
};

Graph *createGraph(int v)
{
    Graph *graph = new Graph;
    graph->v = v;
    graph->adj = new Node *[v];

    for (int i = 0; i < v; i++)
        graph->adj[i] = nullptr;

    return graph;
}

void printGraph(Graph *graph, int n);

void addEdge(Graph *graph, int u, int v)
{
    Node *newNode = new Node;
    newNode->data = v;
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

void freeGraph(Graph *graph, int n)
{
    for (int i = 0; i < n; ++i)
    {
        Node *current = graph->adj[i];
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] graph->adj;
    delete graph;
}

void unionGraph(Graph *graph1, Graph *graph2, Graph *result, int n)
{
    for (int i = 0; i < n; i++)
    {
        set<int> s;
        Node *temp1 = graph1->adj[i];
        while (temp1 != nullptr)
        {
            if (temp1->data != i)
                s.insert(temp1->data);
            temp1 = temp1->next;
        }

        Node *temp2 = graph2->adj[i];
        while (temp2 != nullptr)
        {
            if (temp2->data != i)
                s.insert(temp2->data);
            temp2 = temp2->next;
        }

        for (int j : s)
        {
            addEdge(result, i, j);
        }
    }
}

void intersectionGraph(Graph *graph1, Graph *graph2, Graph *result, int n)
{
    for (int i = 0; i < n; i++)
    {
        set<int> s, s2, common;
        Node *temp1 = graph1->adj[i];
        while (temp1 != nullptr)
        {
            if (temp1->data != i)
                s.insert(temp1->data);
            temp1 = temp1->next;
        }

        Node *temp2 = graph2->adj[i];
        while (temp2 != nullptr)
        {
            if (temp2->data != i)
                s2.insert(temp2->data);
            temp2 = temp2->next;
        }

        for (int j : s)
        {
            if (s2.find(j) != s2.end())
                common.insert(j);
        }

        for (int j : common)
        {
            addEdge(result, i, j);
        }
    }
}

void printGraph(Graph *graph, int n)
{
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        while (graph->adj[i] != NULL)
        {
            if (graph->adj[i]->data != i)
                a[i][graph->adj[i]->data] = 1;
            graph->adj[i] = graph->adj[i]->next;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of nodes in your graph:";
    cin >> n;
    Graph *graph = createGraph(n);

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
                    addEdge(graph, e - 1, s - 1);
                    addEdge(graph, s - 1, e - 1);
                }
            }
            else
                cout << "Invalid choice try again\n";
        }
        else
            break;
    }

    Graph *graph2 = createGraph(n);

    cout << "\nsecond\n";
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
                    addEdge(graph2, e - 1, s - 1);
                    addEdge(graph2, s - 1, e - 1);
                }
            }
            else
                cout << "Invalid choice try again\n";
        }
        else
            break;
    }

    Graph *unionResult = createGraph(n);
    unionGraph(graph, graph2, unionResult, n);

    Graph *intersectionResult = createGraph(n);
    intersectionGraph(graph, graph2, intersectionResult, n);

    cout << "Union\n";
    printGraph(unionResult, n);

    cout << "Intersection\n";
    printGraph(intersectionResult, n);

    freeGraph(graph, n);
    freeGraph(graph2, n);
    freeGraph(unionResult, n);
    freeGraph(intersectionResult, n);

    return 0;
}
