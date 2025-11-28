#include <iostream>
#include <string>
using namespace std;

enum State { q0, q1, q2, q3, q4 };

bool acceptsTwoOrThreeOnes(const string& input) {
    State currentState = q0;

    for (size_t i = 0; i < input.length(); ++i) {
        char ch = input[i];

        if (ch != '0' && ch != '1') {
            cout << "Invalid character in input: " << ch << endl;
            return false;
        }

        switch (currentState) {
            case q0:
                currentState = (ch == '1') ? q1 : q0;
                break;

            case q1:
                currentState = (ch == '1') ? q2 : q1;
                break;

            case q2:
                currentState = (ch == '1') ? q3 : q2;
                break;

            case q3:
                currentState = (ch == '1') ? q4 : q3;
                break;

            case q4:
                currentState = q4;   // Once more than 3 ones, stay in q4
                break;
        }
    }

    // Accept only if total number of 1s = 2 or 3
    return (currentState == q2 || currentState == q3);
}

int main() {
    string input;
    cout << "Enter a binary string (only 0s and 1s): ";
    cin >> input;

    if (acceptsTwoOrThreeOnes(input)) {
        cout << "The string is accepted (has exactly 2 or 3 ones)." << endl;
    } else {
        cout << "The string is rejected." << endl;
    }

    return 0;
}
