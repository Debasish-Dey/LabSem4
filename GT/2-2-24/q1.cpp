#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
int v1;
void makegraph(vector<vector<int>> &graph1){
    for (int i = 0; i < v1; ++i){
        for (int j = 0; j < v1; ++j) graph1[i][j]=0;
    }
    int e1 , x,y;
    cout << "No. of edges for graph 1: ";
    cin >> e1;
    for (int i = 0; i < e1; ++i){
        cin >> x >> y;
        if (x != y){
            graph1[x][y] = 1;
            graph1[y][x] = 1;
        }
    }
}
void print(vector<vector<int>> &graph1){
    for (int i = 0; i < v1; ++i){
        for (int j = 0; j < v1; ++j)  cout << graph1[i][j] << " ";
        cout << endl;
    }
}
int main(){
    cout << "No. of vertices for graph 1: ";
    cin >> v1;
    vector<vector<int>> graph1(v1,vector<int>(v1));
    makegraph(graph1);
    vector<vector<int>> graph2(v1,vector<int>(v1));
    makegraph(graph2);
    vector<vector<int>> unionGraph(v1,vector<int>(v1)) ,intersectionGraph(v1,vector<int>(v1));
    for (int i = 0; i < v1; ++i){
        for (int j = 0; j < v1; ++j){
            if(graph1[i][j]==1 || graph2[i][j]==1) unionGraph[i][j]=1;
            else unionGraph[i][j]=0;
            if(graph1[i][j]==1 && graph2[i][j]==1)  intersectionGraph[i][j]=1;
            else intersectionGraph[i][j]=0;
        }
    }
    cout << "\nUnion of the graphs:\n";
    print(unionGraph);
    cout << "\nIntersection of the graphs:\n";
    print(intersectionGraph);
}