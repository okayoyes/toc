#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string w;
    cout << "Enter string over {a,b}: ";
    cin >> w;

    stack<char> st;
    int i = 0;

    // Push for every 'a'
    while (i < w.length() && w[i] == 'a') {
        st.push('A');
        i++;
    }

    // Pop for every 'b'
    while (i < w.length() && w[i] == 'b') {
        if (st.empty()) {
            cout << "Rejected\n";
            return 0;
        }
        st.pop();
        i++;
    }

    // Accept only if:
    // stack is empty AND we consumed entire string
    if (st.empty() && i == w.length())
        cout << "Accepted (a^n b^n)\n";
    else
        cout << "Rejected\n";

    return 0;
}
