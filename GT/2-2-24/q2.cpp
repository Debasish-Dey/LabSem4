#include<bits/stdc++.h>
using namespace std;
int color[3];
bool isBipartite(int g[][3], int V){
    for(int i = 0; i < V; i ++) color[i] = -1;
    queue<int> q;
    q.push(0);
    color[0] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i = 0; i < V; i ++){
            // if adjacent node is not coloured
            if((g[node][i]) and (color[i] == -1)) {
                color[i] = !color[node];
                q.push(i);
                }
            // if it has same color return false
            else if(g[node][i] and (color[i] == color[node])) return false;
        }
    }

    return true;
}
bool isCompleteBipartite(int g[][3], int V){
    if(!isBipartite(g, V)) return false;
    for(int i = 0; i <  V; i ++){
        for(int j = 0; j < V; j ++){
            // if and j are of same set then color must be different
            if(color[i] == color[j] && g[i][j] == 1) return false;
            else if(color[i] != color[j] && g[i][j] == 0) return false;
        }
    }
    return true;
}
int main(){
    int V = 3;
    int g[V][3] = { 
        {0, 0, 1},
        {0, 0, 1},
        {1, 1, 0}
    };
    if(isBipartite(g, 3))cout << "Yes, it is bipartite\n";
    else cout << "No, it is bipartite\n";    

    if(isCompleteBipartite(g, 3))cout << "Yes, it is Complete bipartite\n";
    else cout << "No, it is bipartite\n"; 
    return 0;
}