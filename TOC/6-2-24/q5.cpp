//4th symbol from right is always 1

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
            if(state[0]==5){
                state.push_back(5);
                state.erase(state.begin());
                continue;
            }
            if(s[i]=='1'){
                if(state[0]==0){
                    state.push_back(1);
                    state.push_back(0);
                }
                else if(state[0]==1){
                    state.push_back(2); 
                }
                else if(state[0]==2){
                    state.push_back(3);
                }
                else if(state[0]==3){
                    state.push_back(4);
                }
            }
            else if(s[i]=='0'){
                if(state[0]==0){
                    state.push_back(0);
                }
                else if(state[0]==1){
                    state.push_back(2);
                }
                else if(state[0]==2){
                    state.push_back(3);
                }
                else if(state[0]==3){
                    state.push_back(4);
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
        if(i==4){
        cout << "ACCEPTED" << endl;
        return 0;
        }
    }
    cout << "NOT ACCEPTED"<<endl;
    return 0;
}