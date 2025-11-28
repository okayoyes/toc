#include <iostream>
#include <string>
using namespace std;

enum State { EE, EO, OE, OO }; // E = even, O = odd

int main() {
    string w;
    cout << "Enter string over {a,b}: ";
    cin >> w;

    State s = EE; // Start with even a's and even b's

    for (char c : w) {
        if (s == EE) 
            s = (c == 'a') ? OE : EO;
        else if (s == EO) 
            s = (c == 'a') ? OO : EE;
        else if (s == OE) 
            s = (c == 'a') ? EE : OO;
        else if (s == OO) 
            s = (c == 'a') ? EO : OE;
    }

    if (s == EE)
        cout << "Accepted (even a's and even b's)\n";
    else
        cout << "Rejected\n";

    return 0;
}
