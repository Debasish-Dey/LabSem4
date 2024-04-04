#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
void print_dfa(vector<vector<vector<int>>> dfa, vector<vector<int>> states){
    int temp = 0;
    for (int i = 0; i < states.size(); i++){
        for (int j = 0; j < states[i].size(); j++) cout << states[i][j];
        cout << "\t";
        for (int j = 0; j < 2; j++){
            for (auto k : dfa[i][j]) cout << k;
            if (dfa[i][j].size()==0){
                temp = 1;
                cout << "$";
            }
            cout << "\t";
        }
        cout << "\n";
    }
    if (temp == 1) cout << "$\t$\t$\n";
}
void convertnfatodfa(vector<vector<vector<int>>> &nfa, vector<int> &final){
    vector<vector<vector<int>>> dfa;
    queue<vector<int>> q;
    vector<vector<int>> states;
    set<vector<int>> s;
    q.push({0});
    while (q.size() != 0){
        vector<int> temp = q.front();
        q.pop();
        int x = s.size();
        s.insert(temp);
        if (s.size() != x){
            states.push_back(temp);
            vector<vector<int>> chirag;
            for (int z = 0; z < 2; z++){
                set<int> temp1;
                for (auto it : temp){
                    for (auto mn : nfa[it][z]) temp1.insert(mn);
                }
                vector<int> temp2;
                for (auto it : temp1)  temp2.push_back(it);
                chirag.push_back(temp2);
                if(temp2.size()!=0) q.push(temp2);
            }
            dfa.push_back(chirag);
        }
    }
    print_dfa(dfa, states);
}
int main(){
    cout << "Enter the number of states in nfa:";
    int nfa_state;
    cin >> nfa_state;
    vector<vector<vector<int>>> nfa;
    for (int i = 0; i < nfa_state; i++){
        vector<vector<int>> temp;
        for (int k = 0; k < 2; k++){
            cout << "Enter the number of transition for " << k << " from state " << i << " :";
            int x;
            cin >> x;
            vector<int> abc(x);
            if (x > 0) cout << "enter the transitions:";
            for (int j = 0; j < x; j++)  cin >> abc[j];
            temp.push_back(abc);
        }
        nfa.push_back(temp);
    }
    int final_state;
    cout << "Enter the number of final state in nfa:";
    cin >> final_state;
    vector<int> final(final_state);
    if (final_state > 0) cout << "Enter the states :";
    for (int i = 0; i < final_state; i++)  cin >> final[i];
    convertnfatodfa(nfa, final);
}