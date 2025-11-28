#include <iostream>
#include <string>
using namespace std;

enum State { q0, q1, q2, q3 };

bool acceptsThreeConsecutiveOnes(const string& input) {
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
                currentState = (ch == '1') ? q2 : q0;
                break;

            case q2:
                currentState = (ch == '1') ? q3 : q0;
                break;

            case q3:
                currentState = q3; // stay in accept state
                break;
        }
    }

    return (currentState == q3);
}

int main() {
    string input;

    cout << "Enter a binary string (only 0s and 1s): ";
    cin >> input;

    if (acceptsThreeConsecutiveOnes(input)) {
        cout << "The string is accepted (contains '111')." << endl;
    } else {
        cout << "The string is rejected (does not contain '111')." << endl;
    }

    return 0;
}
