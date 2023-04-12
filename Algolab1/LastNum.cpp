// Problem: 주어진 정수의 합 구하기
// 국민대학교 과학기술대학 정보보안암호수학과 3학년 20202101 이수현

#include <iostream>
using namespace std;

int main() {
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        unsigned int numData, data;
        unsigned long long lastnum = 1;

        cin >> numData;

        for (int j = 0; j < numData; j++) {
            cin >> data;
            lastnum *= data;
            lastnum %= 10;
        }
        cout << lastnum << endl;
    }
    return 0;
}