#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of states in dfa:";
    cin >> n;
    unordered_map<int, vector<int>> tt;
    for (int i = 0; i < n; i++){
        vector<int> temp(2);
        cout << "Enter output state for input 0:";
        cin >> temp[0];
        cout << "Enter output state for input 1:";
        cin >> temp[1];
        tt[i] = temp;
    }
    cout << "Transition Table: " << endl;
    for (auto i : tt){
        cout << i.first << ": " << "{" << i.second[0] << "," << i.second[1] << "}" << endl;
    }
    int f;
    cout << "Enter number of final states:";
    cin >> f;
    unordered_set<int> final;
    for (int i = 0; i < f; i++){
        int x;
        cin >> x;
        final.insert(x);
    }
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            for (int k = 0; k < 2; k++){
                if ((final.count(tt[i][k]) && !final.count(tt[j][k])) || (!final.count(tt[i][k]) && final.count(tt[j][k]))){
                    mat[i][j] =mat[j][i]= 1;
                }
            }
        }
    }
    cout << "\nStates which can be combined are: " << endl;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (mat[i][j] == 0){
                cout << i << " " << j << endl;
                for (int k = 0; k < n; ++k){
                    if (tt[k][0] == j) tt[k][0] = i;
                    if (tt[k][1] == j) tt[k][1] = i;
                }
            }
        }
    }
    unordered_set<int> visited;
    unordered_map<int, vector<int>> min_dfa;
    for (int i = n - 1; i >= 0; i--){
        if (visited.find(i) == visited.end()){
            for (int j = 0; j < i; j++){
                if ((tt[i][0] == tt[j][0]) && (tt[i][1] == tt[j][1])){
                    visited.insert(i);
                    visited.insert(j);
                }
            }
            min_dfa[i] = tt[i];
        }
    }
    cout << "Transition Table: " << endl;
    for (auto i : min_dfa){
        cout << i.first << ": " << "{" << i.second[0] << "," << i.second[1] << "}" << endl;
    }
    return 0;
}