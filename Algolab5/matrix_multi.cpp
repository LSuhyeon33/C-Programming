// Problem: 행렬곱셈
// 국민대학교 과학기술대학 정보보안암호수학과 3학년 20202101 이수현

#include <iostream>
using namespace std;

void matrix_multi(int r, int s, int t);

int main()
{
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int r, s, t;
        cin >> r >> s >> t;

        matrix_multi(r, s, t);
    }
    return 0;
}

void matrix_multi(int r, int s, int t) {

    int** matA = new int* [r];      // 배열 A
    for (int i = 0; i < r; i++) {
        matA[i] = new int[s];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            cin >> matA[i][j];
        }
    }

    int** matB = new int* [s];      // 배열 B
    for (int i = 0; i < s; i++) {
        matB[i] = new int[t];
    }
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < t; j++) {
            cin >> matB[i][j];
        }
    }

    int** mat_mul = new int* [r];       // 배열 결과
    for (int i = 0; i < r; i++) {
        mat_mul[i] = new int[t];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            mat_mul[i][j] = 0;
        }
    }

    for (int i = 0; i < r; i++) {       // 행렬 곱셈
        for (int j = 0; j < t; j++) {
            for (int k = 0; k < s; k++) {
                mat_mul[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    for (int i = 0; i < r; i++) {       // 출력
        for (int j = 0; j < t; j++) {
            cout << mat_mul[i][j] << " ";
        }
        cout << endl;
    }
}