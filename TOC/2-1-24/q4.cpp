#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>chirag;
    for(int i=0;i<n;i++){
        string m;
        cin>>m;
        chirag.push_back(m);
    }
    vector<string>ans;
    ans.push_back("");
    ans.push_back(chirag[0]);
    for(int i=1;i<n;i++){
        int x=ans.size();
        for(int j=0;j<x;j++){
            ans.push_back(ans[j]+chirag[i]);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}