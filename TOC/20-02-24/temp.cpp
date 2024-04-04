#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> t; // Transition function
vector<char> o; // Output vector for Moore machine

void print_moore() {
    cout << "\nMoore Machine\n";
    cout << "===============\n";
    cout << "Q\t";
    for(int j = 0; j < m; j++) cout << j << "\t";
    cout << "o/p\n\n";
    for(int i = 0; i < n; i++) {
        cout << i << "\t";
        for(int j = 0; j < m; j++) {
            cout << t[i][j] << "\t";
        }
        cout << o[i] << endl; // Output is now associated with the state
    }
    cout << endl;
}

int main() {

    // Set the number of states and symbols
    cout << "Enter the number of states: ";
    cin >> n;
    cout << "Enter the number of symbols: ";
    cin >> m;

    // Input Moore machine
    t.resize(n, vector<int>(m, -1)); // Initialize the transition function
    o.resize(n); // Initialize the output vector
    for(int i = 0; i < n; i++) {
        cout << "Enter the outputs for state " << i << ": ";
        cin >> o[i]; // Input the output for state i
        for(int j = 0; j < m; j++) {
            cout << "Enter the next state when the current state is " << i << " and the input is " << j << ": ";
            cin >> t[i][j]; // Input the next state for state i and input j
        }
    }

    // Print the Moore machine
    print_moore();

    return 0;
}
