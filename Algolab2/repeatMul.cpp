#include <iostream>
using namespace std;

int numdigits(unsigned long long n) {
    int digit = 0;

    while (n > 0) {
        n /= 10;
        digit++;
    }
    return digit;
}

int mul_func(unsigned long long num) {
    unsigned long long mul = 1;
    int digit;

    digit = numdigits(num);

    for (int i = 0; i < digit; i++) {
        if (num % 10 != 0) {
            mul *= num % 10;
        }
        num /= 10;
    }
    return mul;
}

int main() {
    int numTestcase;
    cin >> numTestcase;

    for (int i = 0; i < numTestcase; i++) {
        unsigned long long data;
        unsigned long long mul = 1;

        cin >> data;

        while ((data / 10) != 0) {
            mul = mul_func(data);
            data = mul;
        }
        cout << mul << endl;
    }
    return 0;
}