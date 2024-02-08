//if starts with 0 ends with 1, starts with 1 ends with 0

#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;
    vector<int> state;
    state.push_back(0);
    for(int i=0; i<s.length(); i++){
        int x = state.size();
        for(int j=0; j<x; j++){
            if(state[0]==4){
                state.push_back(4);
                state.erase(state.begin());
                continue;
            }
            if(s[i]=='1'){
                if(state[0]==0){
                    state.push_back(1);
                }
                else if(state[0]==1){
                    state.push_back(1); 
                }
                else if(state[0]==3){
                    state.push_back(3);
                    state.push_back(2);
                }
            }
            else if(s[i]=='0'){
                if(state[0]==0){
                    state.push_back(3);
                }
                else if(state[0]==1){
                    state.push_back(1);
                    state.push_back(2);
                }
                else if(state[0]==3){
                    state.push_back(3);
                }
            }
            else{
                cout <<"INVALID STRING" << endl;
                return 0;
            }
            state.erase(state.begin());
        }
    }

    for(auto i: state){
        if(i==2){
        cout << "ACCEPTED" << endl;
        return 0;
        }
    }
    cout << "NOT ACCEPTED"<<endl;
    return 0;
}