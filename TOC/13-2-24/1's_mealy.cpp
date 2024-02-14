//1's complement of a string using mealy machine
#include <iostream>
#include <string>

using namespace std;

enum State { Initial };

State process(State currentState, char bit, string& result) {
    switch (currentState) {
        case Initial:
            if (bit == '0') {
                result += '1';
                return Initial;
            } else if (bit == '1') {
                result += '0';
                return Initial;
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
        currentState = process(currentState, bit, result);
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
