#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int src, dest, weight;
};
struct Subset {
    int parent;
    int rank;
};
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}
int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
void KruskalMST(vector<Edge>& edges, int V, int E) {
    vector<Edge> result(V); 
    int e = 0; 
    sort(edges.begin(), edges.end(), compareEdges); 
    vector<Subset> subsets(V); 
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int i = 0; 
    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) { 
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    cout << "Edges of MST: \n";
    for (i = 0; i < e; ++i)
        cout << result[i].src << " - " << result[i].dest << " \tWeight: " << result[i].weight << endl;
}
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    vector<Edge> edges(E);
    cout << "Enter the edges in format 'source destination weight':" << endl;
    for (int i = 0; i < E; ++i)
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    KruskalMST(edges, V, E);
    return 0;
}