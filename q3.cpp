#include <iostream>
#include <string>
using namespace std;

int main() {
    string w;
    cout << "Enter string over {a,b}: ";
    cin >> w;

    // Check minimum length
    if (w.length() < 4) {
        cout << "Rejected (length < 4)\n";
        return 0;
    }

    // Extract first 2 and last 2 characters
    string first2 = w.substr(0, 2);
    string last2 = w.substr(w.length() - 2, 2);

    // Compare
    if (first2 == last2)
        cout << "Accepted\n";
    else
        cout << "Rejected\n";

    return 0;
}
