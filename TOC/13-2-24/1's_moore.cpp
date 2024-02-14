#include <iostream>
#include <string>

using namespace std;

enum State { Initial, Complement };

State nextState(State currentState, char bit) {
    switch (currentState) {
        case Initial:
            if (bit == '0') {
                return Initial;
            } else if (bit == '1') {
                return Complement;
            } else {
                cerr << "Invalid input!\n";
                return currentState;
            }
        case Complement:
            if (bit == '0') {
                return Complement;
            } else if (bit == '1') {
                return Complement;
            } else {
                cerr << "Invalid input!\n";
                return currentState;
            }
        default:
            cerr << "Invalid state!\n";
            return currentState;
    }
}

string onesComplement(const string& input) {
    string result;
    State currentState = Initial;

    for (char bit : input) {
        currentState = nextState(currentState, bit);
        if (currentState == Complement) {
            result += '1';
        } else {
            result += '0';
        }
    }

    return result;
}

int main() {
    string input;

    cout << "Enter a binary string: ";
    cin >> input;

    string result = onesComplement(input);

    cout << "The 1's complement of " << input << " is: " << result << endl;

    return 0;
}
