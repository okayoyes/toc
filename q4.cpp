#include <iostream>
#include <string>
using namespace std;

int main() {
    string w;
    cout << "Enter string over {a,b}: ";
    cin >> w;

    if (w.length() >= 2 && w[0] == 'a' && w[w.length() - 1] == 'b')
        cout << "Accepted\n";
    else
        cout << "Rejected\n";

    return 0;
}
