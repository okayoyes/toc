#include <iostream>
#include <string>
using namespace std;

string incrementBinaryTM(string tape) {
    tape += "_";  // add blank to the right
    int head = 0;
    string state = "q0";

    while (state != "q_accept") {
        if (head < 0) return "ERROR";  // safety
        if (head >= (int)tape.size()) tape += "_";

        char symbol = tape[head];

        // -------------------------
        // STATE q0: move to the end
        // -------------------------
        if (state == "q0") {
            if (symbol == '0' || symbol == '1') {
                head++;  // move right
            }
            else if (symbol == '_') {
                head--;      // move to last bit
                state = "q1";
            }
            else {
                return "ERROR";
            }
        }

        // -------------------------
        // STATE q1: perform increment
        // -------------------------
        else if (state == "q1") {
            if (symbol == '1') {
                tape[head] = '0';  // carry continues
                head--;
            }
            else if (symbol == '0') {
                tape[head] = '1';   // carry stops here
                state = "q_accept";
            }
            else if (symbol == '_') {
                // overflow, e.g., 111 → 1000
                tape.insert(tape.begin(), '1');
                state = "q_accept";
            }
            else {
                return "ERROR";
            }
        }
    }

    // Remove trailing blanks
    while (!tape.empty() && tape.back() == '_')
        tape.pop_back();

    return tape;
}

int main() {
    string input;
    cout << "Enter a binary number: ";
    cin >> input;

    string output = incrementBinaryTM(input);
    cout << "After increment: " << output << endl;

    return 0;
}
