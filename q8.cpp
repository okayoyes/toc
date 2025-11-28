#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string w;
    cout << "Enter string (with X in middle): ";
    cin >> w;

    stack<char> st;
    int i = 0;

    // Push characters of w before 'X' onto stack
    while (i < (int)w.length() && w[i] != 'X') {
        st.push(w[i]);
        i++;
    }

    // If no 'X' found -> reject
    if (i == (int)w.length()) {
        cout << "Rejected (no X found)\n";
        return 0;
    }

    i++; // skip 'X'

    // For each char after 'X', it must match top of stack
    while (i < (int)w.length()) {
        if (st.empty() || w[i] != st.top()) {
            cout << "Rejected\n";
            return 0;
        }
        st.pop();
        i++;
    }

    // Accept only if stack is empty (all matched)
    if (st.empty())
        cout << "Accepted (wXw^R)\n";
    else
        cout << "Rejected\n";

    return 0;
}
