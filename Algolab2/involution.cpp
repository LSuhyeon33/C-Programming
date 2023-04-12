#include <iostream>
#include <cmath>
using namespace std;

int numdigits(int n) {
    int digit = 0;

    while (n > 0) {
        n /= 10;
        digit++;
    }
    return digit;
}

int inv_sum(int digit, int n) {
    unsigned int sum = 0, num = 0;

    for (int i = 0; i < digit; i++) {
        num = n % 10;
        sum += pow(num, digit);
        n /= 10;
    }
    return sum;
}

int main() {
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        unsigned int n, digit, sum = 0;

        cin >> n;
        digit = numdigits(n);
        sum = inv_sum(digit, n);
 
        cout << (n == sum) << endl;
    }
    return 0;
}