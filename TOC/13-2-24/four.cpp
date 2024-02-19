// output when 110 is substring outut is b when 101 is substring output is a else output is c
#include <iostream>
#include <string>
using namespace std;

string mealy(string input) {
    string output = "";
    int state = 0;
    for (char ch : input) {
        if (state == 0) {
            if (ch == '0'){
                output += 'c';
                state = 0;
            }
            else{
                output += 'c';
                state = 1;
            }
        } else if (state == 1) {
            if (ch == '0'){
                output += 'b';
                state = 0;
            }else{
                output += 'a';
                state = 2;
            }
        } else {
            if (ch == '0'){
                output += 'c';
                state = 0;
            }else{
                output += 'b';
                state = 1;
            }
        }
    }
    return output;
}

string moore(string input) {
    string output = "a";
    int state = 0;
    for (char ch : input) {
        if (state == 0) {
            if (ch == '0'){
                output += 'c';
                state = 0;
            }
            else{
                output += 'c';
                state = 1;
            }
        } else if (state == 1) {
            if (ch == '0'){
                output += 'b';
                state = 0;
            }else{
                output += 'a';
                state = 2;
            }
        } else {
            if (ch == '0'){
                output += 'c';
                state = 0;
            }else{
                output += 'b';
                state = 1;
            }
        }
    }
    return output;
}

int main() {
    string s; cout<<"Enter string: "; cin>>s;
    cout<<"The moore output is: "<<moore(s)<<endl;
    cout<<"The mealy output is: "<<mealy(s)<<endl;
    return 0;
}