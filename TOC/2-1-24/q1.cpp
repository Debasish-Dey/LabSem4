#include<iostream>
using namespace std;

int main()
{
    string v = {'0', '1'};
    cout << "Enter the number of strings: ";
    int x;
    cin>> x;
    while(x--){
        cout << "Enter string: ";
        string s;
        cin>> s;
        for(int i=0; i<s.length(); i++){
            if(s[i]!=v[0] && s[i]!=v[1]){
                cout << "Invalid String";
                break;
            }
            if(i==s.length()-1)
            cout << "Valid String";
        }
        cout << endl;
    }

    return 0;
}