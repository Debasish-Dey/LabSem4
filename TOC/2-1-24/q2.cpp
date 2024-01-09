#include<iostream>
using namespace std;

int main()
{
    string a;
    cout << "Enter a string: ";
    cin >> a;

    string b;
    cout << "Enter second string: ";
    cin >> b;
    for(int i=0;i<b.size(); i++){
        a.push_back(b[i]);
    }

    cout << a;

    return 0;
}