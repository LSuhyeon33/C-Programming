// Problem: 주어진 정수의 합 구하기
// 국민대학교 과학기술대학 정보보안암호수학과 3학년 20202101 이수현

#include <iostream>
using namespace std;

void numArray(int a, int b, int c) {
    if (a <= b) {
        if (b <= c) cout << a << " " << b << " " << c << endl;
        else if (a <= c) cout << a << " " << c << " " << b << endl;
        else cout << c << " " << a << " " << b << endl;
    } else {
         if (a <= c) cout << b << " " << a << " " << c << endl;
         else if (b <= c)cout << b << " " << c << " " << a << endl;
         else cout << c << " " << b << " " << a << endl;
    }
}

int main()
{
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int a, b, c;

        cin >> a >> b >> c;    
        numArray(a, b, c);
    }
    return 0;
}