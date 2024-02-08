//convert nfa to dfa

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout << "Enter number of states of NFA: ";
    cin >> n;
    vector<vector<vector<int>>> adjmat(n);
    for(int i=0; i<n; i++){
        vector<vector<int>> t;
        int a;
        cout << "Enter the number of transitions of 0 from state "<<i+1<< " :"<<endl;
        cin >> a;
        if(a>0){
            cout << "Enter the transition of 0 for " << i+1 << "state: " << endl;
            vector<int> x;
            for(int i=0; i<a; i++){
                int m;
                cin >> m;
                x.push_back(m);
            }
            t.push_back(x);
        }
        cout << "Enter the number of transitions of 1 from state " << i+1 << " :";
        cin >> a;
        if(a>0){
            cout << "Enter the transition of 1 for " << i+1 << "state: " << endl;
            vector<int> y;
            for(int i=0; i<a; i++){
                int m;
                cin >> m;
                y.push_back(m);
            }
            t.push_back(y);
        }
        adjmat.push_back(t);
    }
    
    int init;
    cout << "Enter the initial state: ";
    cin >> init;

    if(init>n || init <=0){
        cout << "Entered value out of range"<<endl;
        return 0;
    }
    init--;
}
