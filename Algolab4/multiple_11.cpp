// Problem: 11의 배수
// 국민대학교 과학기술대학 정보보안암호수학과 3학년 20202101 이수현

#include <iostream>
using namespace std;

#define MAX     100     // 입력 숫자 최대 길이

int size_num(char n[MAX]);     // num 크기 구하기
void multi(char n[MAX]);        // 배수 계산하기

int main() {
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        static char num[MAX];

        cin >> num;
        multi(num);
    }
    return 0;
}

int size_num(char n[MAX]) {
    int s = 0;
    int index = 0;
    while (n[index] != 0) {
        s += 1;
        index++;
    }
    return s;
}

void multi(char n[MAX]) {
    int size, nzero;

    size = size_num(n);

    for (int i = (size - 1); i > 0; i--) {
        if (n[i - 1] >= n[i]) {
            n[i - 1] = '0' + (n[i - 1] - n[i]);
        }
        else {
            nzero = i - 2;
            while (n[nzero] == '0') {
                n[nzero] = '9';
                nzero--;
            }
            n[nzero] -= 1;
            n[i - 1] = '0' + ((10 + n[i - 1]) - n[i]);
        }
    }
    if (n[0] == '0') {
        if (n[1] == '0') {
            for (int i = 2; i < size; i++) {
                cout << n[i];
            }
        }
        else {
            for (int i = 1; i < size; i++) {
                cout << n[i];
            }
        }
        cout << endl;
    }
    else {
        cout << '0' << endl;
    }
}