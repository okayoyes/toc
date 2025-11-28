#include <iostream>
#include <string>
using namespace std;

bool L1(const string &w) {
    // L1: length >= 4 and first 2 chars == last 2 chars
    if (w.length() < 4) return false;
    return (w.substr(0, 2) == w.substr(w.length() - 2, 2));
}

bool L2(const string &w) {
    // L2: length >= 2, starts with 'a' and ends with 'b'
    return (w.length() >= 2 && w.front() == 'a' && w.back() == 'b');
}

int main() {
    string w;
    cout << "Enter string over {a,b}: ";
    cin >> w;

    // Validate input alphabet
    for (char c : w) {
        if (c != 'a' && c != 'b') {
            cout << "Invalid input: only 'a' and 'b' are allowed.\n";
            return 0;
        }
    }

    cout << "\nString: " << w << "\n\n";

    cout << "L1(w): " << (L1(w) ? "True" : "False") << "    "
         << "(length >= 4 and first2 == last2)\n";
    cout << "L2(w): " << (L2(w) ? "True" : "False") << "    "
         << "(length >= 2, starts with 'a' and ends with 'b')\n\n";

    cout << "Union (L1 ∪ L2): " << ((L1(w) || L2(w)) ? "Accepted" : "Rejected") << "\n";
    cout << "Intersection (L1 ∩ L2): " << ((L1(w) && L2(w)) ? "Accepted" : "Rejected") << "\n";

    // Concatenation check: does w = w1 w2 with w1 in L1 and w2 in L2?
    bool concat = false;
    for (size_t i = 1; i < w.length(); ++i) {
        string w1 = w.substr(0, i);
        string w2 = w.substr(i);
        if (L1(w1) && L2(w2)) {
            concat = true;
            break;
        }
    }
    cout << "Concatenation (L1L2): " << (concat ? "Accepted" : "Rejected") << "\n";

    return 0;
}
