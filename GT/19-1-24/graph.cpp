#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Graph {
    private:
    int V;
    vector<list<int>> adjList;
    public:
    Graph(int ver): V(ver), adjList(ver){}
    void addEdge(int v, int w){
        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }
    int getNumVertices(){
        return V;
    }
    int getNumEdges() {
        int edges = 0;
        for(int i=0; i<V; i++){
            edges += adjList[i].size();
        }
        return edges /2;
    }
    int getDegree(int v){
        return adjList[v].size();
    }
    bool hasSelfLoop() const {
        for (int i = 0; i < V; ++i) {
            for (int neighbor : adjList[i]) {
                if (i == neighbor) {
                    return true;
                }
            }
        }
        return false;
    }
    bool hasParallelEdges() const {
        vector<vector<bool>> edgeMatrix(V, vector<bool>(V, false));

        for (int i = 0; i < V; ++i) {
            for (int neighbor : adjList[i]) {
                if (edgeMatrix[i][neighbor]) {
                    return true;
                }
                edgeMatrix[i][neighbor] = true;
                edgeMatrix[neighbor][i] = true;
            }
        }
        return false;
    }
    bool isCompleteGraph() const {
        unordered_set<int> s;
        for(int i=0; i<V; i++){
            for(auto it : adjList[i]){
                if(it != i) 
                s.insert(it);
            }
            if(s.size()!=V-1) return false;
        }
        return true;
    }
};
int main(){
    int nv, ne;
    cout << "Enter the number of vertices: ";
    cin >> nv;
    Graph g(nv);
    while(1){
        cout << "Enter 1 to add edges\nEnter 2 to terminate"<<endl;
        int x;
        cin >> x;
        if(x==1){
        cout << "Enter the edges (v1, v2): " << endl;
        int v1,v2;
        cin >> v1 >> v2;
        g.addEdge(v1, v2);
        }
        else
        break;
    }
    cout << "\nNumber of Vertices: " << g.getNumVertices() <<endl;
    cout << "Number of Edges: " << g.getNumEdges() << endl;
    for(int i=0; i<g.getNumVertices(); i++){
        cout << "Degree of vertex "<< i << " :" << g.getDegree(i) <<endl;
    }
    cout << "Has Self Loop: " << (g.hasSelfLoop() ? "Yes" : "No") << endl;
    cout << "Has Parallel Edges: " << (g.hasParallelEdges() ? "Yes" : "No") << endl;
    cout << "Is Complete Graph: " << (g.isCompleteGraph() ? "Yes" : "No") << endl;
    return 0;
}