#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int x,y;
    int v1;
    cout<<"No. of vertices for graph 1: ";
    cin>>v1;
    int graph1[v1][v1];
    int deg1[v1];
    for(int i=0;i<v1;++i){
        for(int j=0;j<v1;++j){
            if(i!=j) graph1[i][j]=0;
            else graph1[i][j]=1;
        }
        deg1[i]=-1;
    }
    int e1;
    cout<<"No. of edges for graph 1: ";
    cin>>e1;
    for(int i=0;i<e1;++i){
        cin>>x>>y;
        graph1[x][y]+=1;
        graph1[y][x]+=1;
    }

    int v2;
    cout<<"No. of vertices for graph 2: ";
    cin>>v2;
    int graph2[v2][v2];
    int deg2[v2];
    for(int i=0;i<v2;++i){
        for(int j=0;j<v2;++j){
            if(i!=j) graph2[i][j]=0;
            else graph2[i][j]=1;
        }
        deg2[i]=-1;
    }
    int e2;
    cout<<"No. of edges for graph 2: ";
    cin>>e2;
    for(int i=0;i<e2;++i){
        cin>>x>>y;
        graph2[x][y]+=1;
        graph2[y][x]+=1;
    }

    for(int i=0;i<v1;++i){
        int c=0;
        for(int j=0;j<v1;++j){
            if(i==j) continue;
            if(graph1[i][j]>=1)
                c++;
        }
        deg1[i]=c-1;
    }
    sort(deg1, deg1+v1);
    for(int i=0;i<v2;++i){
        int c=0;
        for(int j=0;j<v2;++j){
            if(i==j) continue;
            if(graph2[i][j]>=1)
                c++;
        }
        deg2[i]=c-1;
    }
    sort(deg2, deg2+v2);

    if(v1!=v2) cout<<"Not isomorphic"<<endl;
    bool isomorphic = true;
    for(int i=0;i<v1;++i){
        if(deg1[i]!=deg2[i]){
            isomorphic = false;
            break;
        }
    }
    if(isomorphic) cout<<"Isomorphic graphs\n";
    else cout<<"Not isomorphic\n";
    return 0;
}