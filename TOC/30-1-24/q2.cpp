//copy se dekh lena 
#include<iostream>
using namespace std;

int main(){
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int state=0 , temp=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='0'){
            if(state==0) state = 1;
            else if(state==1) state = 5;
            else if(state==2) state = 1;
            else if(state==3) state = 5;
            else if(state==4) state = 5;
            else if(state==5) state = 5;
        }
        else if(s[i]=='1'){
            if(state==0) state = 5;
            else if(state==1) state = 2;
            else if(state==2) state = 3;
            else if(state==3) state = 4;
            else if(state==4) state = 3;
            else if(state==5) state = 5;
        }
        else temp=1;
    }
    if(temp) cout << "INVALID STRING" << endl;
    else{
        if(state==4) cout << "ACCEPTED" << endl;
        else cout << "NOT ACCEPTED" << endl;
    }

    return 0;
}