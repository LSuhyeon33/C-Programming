// Problem: 홀수 마방진
// 국민대학교 과학기술대학 정보보안암호수학과 3학년 20202101 이수현

#include <iostream>
#include<fstream>
using namespace std;

void magicSquere(int size);

int main()
{
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int size;
        cin >> size;

        magicSquere(size);
    }
    return 0;
}

void magicSquere(int size) {
    int row = 0;
    int col = size / 2;

    int** mat = new int* [size]; 
    for (int i = 0; i < size; i++) {
        mat[i] = new int[size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mat[i][j] = 0;
        }
    }
    mat[row][col] = 1;

    for (int i = 2; i <= size * size; i++) {
        row -= 1; col += 1;
        if ((row < 0) && (col >= size)) {
            row += 2; col -= 1;
        }
        else if (row < 0) {
            row = size - 1;
        }
        else if (col >= size) {
            col = 0;
        }
        else if (mat[row][col] != 0) {
            row += 2; col -= 1;
        }
        mat[row][col] = i;
    }

    for (int i = 0; i < size; i++) {       // 출력
        for (int j = 0; j < size; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
