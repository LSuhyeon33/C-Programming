#include <iostream>
using namespace std;

int incouse(int a1, int b1, int a2, int b2) {
    int inc = 0;

    if (a1 >= a2) {
        if (b2 <= a1) {
            inc = 0;
        }
        else {
            (b2 <= b1) ? inc = b2 - a1 : inc = b1 - a1;
        }
    }
    else {
        if (b1 <= a2) {
            inc = 0;
        }
        else {
            (b1 <= b2) ? inc = b1 - a2 : inc = b2 - a2;
        }
    }
    return inc;
}

int outcouse(int a1, int b1, int a2, int b2) {
    int outc = 0;

    if (a1 >= a2) {
        if (b2 <= a1) {
            outc = (b2 - a2) + (b1 - a1);
        }
        else {
            (b2 <= b1) ? outc = b1 - a2 : outc = b2 - a2;
        }
    }
    else {
        if (b1 <= a2) {
            outc = (b2 - a2) + (b1 - a1);
        }
        else {
            (b1 <= b2) ? outc = b2 - a1 : outc = b1 - a1;
        }
    }
    return outc;
}

int main() {
    int numTestcase;
    cin >> numTestcase;

    for (int i = 0; i < numTestcase; i++) {
        int a1, b1, a2, b2;
        int inc = 0; int outc = 0;
        cin >> a1 >> b1 >> a2 >> b2;
        
        inc = incouse(a1, b1, a2, b2);
        outc = outcouse(a1, b1, a2, b2);

        cout << inc << " " << outc << endl;
    }
    return 0;
}