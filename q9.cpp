#include <iostream>
#include <string>
using namespace std;

bool simulateTM(string tape) {
    tape += "_"; // blank at the end
    int head = 0;
    string state = "q0";

    while (true) {
        if (head < 0) return false; // safety check
        if (head >= (int)tape.size()) tape += "_";

        char symbol = tape[head];

        // ----------------------
        // STATE q0
        // ----------------------
        if (state == "q0") {
            if (symbol == 'a') {
                tape[head] = 'X';
                state = "q1";
                head++;
            }
            else if (symbol == 'X') {
                head++;
            }
            else if (symbol == 'Y' || symbol == 'Z' || symbol == '_') {
                // check remaining symbols are all marked
                bool ok = true;
                for (size_t i = head; i < tape.size(); ++i) {
                    if (tape[i] == 'a' || tape[i] == 'b' || tape[i] == 'c')
                        ok = false;
                }
                return ok;  // Accept if all processed
            }
            else {
                return false;
            }
        }

        // ----------------------
        // STATE q1
        // ----------------------
        else if (state == "q1") {
            if (symbol == 'a' || symbol == 'X') {
                head++;
            }
            else if (symbol == 'b') {
                tape[head] = 'Y';
                state = "q2";
                head++;
            }
            else if (symbol == 'Y') {
                head++;
            }
            else {
                return false; // missing 'b'
            }
        }

        // ----------------------
        // STATE q2
        // ----------------------
        else if (state == "q2") {
            if (symbol == 'b' || symbol == 'Y') {
                head++;
            }
            else if (symbol == 'c') {
                tape[head] = 'Z';
                state = "q3";
                head--; // move left
            }
            else if (symbol == 'Z') {
                head++;
            }
            else {
                return false; // missing 'c'
            }
        }

        // ----------------------
        // STATE q3  (return to left side)
        // ----------------------
        else if (state == "q3") {
            if (head == 0) {
                state = "q0";
            }
            else if (tape[head] == 'X') {
                head++;
                state = "q0";
            }
            else {
                head--;
            }
        }

        else {
            return false; // unknown state
        }
    }

    return false;
}

int main() {
    string input;
    cout << "Enter a string over {a,b,c}: ";
    cin >> input;

    if (simulateTM(input))
        cout << "String ACCEPTED by Turing Machine (belongs to a^n b^n c^n)" << endl;
    else
        cout << "String REJECTED by Turing Machine" << endl;

    return 0;
}
