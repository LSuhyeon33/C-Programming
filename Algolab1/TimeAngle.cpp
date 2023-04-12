// Problem: 주어진 정수의 합 구하기
// 국민대학교 과학기술대학 정보보안암호수학과 3학년 20202101 이수현

#include <iostream>
using namespace std;

int angleClock(int h, int m) {
    double h_angle, m_angle;
    double angle = 0;

    h_angle = (double)h * 30 + (double)m * 0.5;
    m_angle = (double)m * 6;

    angle = abs(h_angle - m_angle);

    if (angle > 180) {
        angle = 360 - angle;
    }
    angle = (int)angle;
    return angle;
}

int main() {
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int h, m;

        cin >> h >> m;
        cout << angleClock(h, m) << endl;
    }
    return 0;
}