//all strings that does not contain 110 as substring
#include<iostream>
using namespace std;

int main(){
    int state=0;
    string s;
    cout << "Enter the string: ";
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0' && state==0) state=0;
        else if(s[i]=='1' && state==0) state=1;
        else if(s[i]=='0' && state==1) state=0;
        else if(s[i]=='1' && state==1) state=2;
        else if(s[i]=='0' && state==2) state=3;
        else if(s[i]=='1' && state==2) state=2;
        else if(s[i]!='1' && s[i]!='0'){
            cout<<"Invalid String\n";
            return 0;
        }
    }
    if(state==3) cout<<"NOT ACCEPTED\n";
    else cout<<"ACCEPTED\n";
    return 0;
}