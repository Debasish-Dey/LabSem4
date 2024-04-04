#include <iostream>
#include <vector>
using namespace std;
int main(){
    cout << "Enter the no of states of moore machine:";
    int states;
    cin >> states;
    vector<pair<vector<int>, int>> table;
    for (int i = 0; i < states; i++){
        pair<vector<int>, int> p;
        cout << "Enter the output for state " << i;
        int x;
        cin >> x;
        p.second = x;
        for (int j = 0; j < 2; j++){
            cout << "Enter the transition for input " << j << "for state "<<i<<":";
            cin >> x;
            p.first.push_back(x);
        }
        table.push_back(p);
    }
    vector<vector<int>> mealy(states, vector<int>(4));
    for (int i = 0; i < states; i++){
        mealy[i][0] = table[i].first[0];
        mealy[i][2] = table[i].first[1];
        mealy[i][1] = table[table[i].first[0]].second;
        mealy[i][3] = table[table[i].first[1]].second;
    }
    for (int i = 0; i < states; i++){
        cout << i << "\t" << mealy[i][0] << "\t" << mealy[i][1] << "\t" << mealy[i][2] << "\t" << mealy[i][3] << "\n";
    }
} 