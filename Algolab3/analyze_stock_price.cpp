#include <iostream>
using namespace std;

int main() {
    int numTestcase;
    cin >> numTestcase;

    for (int i = 0; i < numTestcase; i++) {
        int num;  // 주가 개수
        cin >> num;
        int prev = 0, curr;
        bool up = false;
        int count = 0;

        for (int i = 0; i < num; i++){
            cin >> curr;
            if (i != 0) {
                if (prev < curr) {
                    up = true;
                }
                else if ((prev > curr) && up == true) {
                    count++;
                    up = false;
                }
            }
            prev = curr;
        }
        cout << count << endl;
    }
    return 0;
}