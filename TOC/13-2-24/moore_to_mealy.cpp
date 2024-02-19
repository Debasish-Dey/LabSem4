#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cout<<"Enter the moore form: ";
    cin>>s;
    int tt[4][2] = {2,0,1,2,3,1,0,3};
    vector<pair<int,char>> v;
    v.push_back({0,'a'});
    v.push_back({1,'b'});
    v.push_back({2,'a'});
    v.push_back({3,'b'});
    int cst=0;
    string str="";
    for(int i=1; i<s.length(); i++) {
        cst = tt[cst][s[i]-'a'];
        for(int j=0; j<v.size(); j++) {
            if(cst==v[j].first)  {
                str+=v[j].second;
                break;
            }
        }
    }
    cout<<"The required mealy form is: "<<str<<endl;
}