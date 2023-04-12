// Problem: 오셀로 게임
// 국민대학교 과학기술대학 정보보안암호수학과 3학년 20202101 이수현

#include <iostream>
using namespace std;

void othello(int num);
void left(char** mat, int row, int col, char go);
void right(char* mat[], int row, int col, char go);
void up(char* mat[], int row, int col, char go);
void down(char* mat[], int row, int col, char go);
void left_up(char* mat[], int row, int col, char go);
void left_down(char* mat[], int row, int col, char go);
void right_up(char* mat[], int row, int col, char go);
void right_down(char* mat[], int row, int col, char go);

int main()
{
    int numTestCase;
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int num;
        cin >> num;
        othello(num);
    }
    return 0;
}

void othello(int num) {
    int white = 0; int black = 0;

    char** mat = new char* [8]; 
    for (int i = 0; i < 8; i++) {
        mat[i] = new char[8];
    }

    for (int i = 0; i < 8; i++) {       // '+'로 초기화
        for (int j = 0; j < 8; j++) {
            mat[i][j] = '+';
        }
    }
    mat[3][3] = 'O'; mat[4][4] = 'O'; mat[3][4] = 'X'; mat[4][3] = 'X';     // 기본값

    for (int i = 0; i < num; i++) {
        int row, col;
        char go;
        cin >> row >> col;
        ((i % 2) == 0) ? go = 'X' : go = 'O';
        mat[row - 1][col - 1] = go;

        left(mat, row - 1, col - 1, go);        // 왼쪽
        right(mat, row - 1, col - 1, go);        // 오른쪽
        up(mat, row - 1, col - 1, go);        // 위
        down(mat, row - 1, col - 1, go);        // 아래
        left_up(mat, row - 1, col - 1, go);        // 왼쪽 위 대각선
        left_down(mat, row - 1, col - 1, go);        // 왼쪽 아래 대각선
        right_up(mat, row - 1, col - 1, go);        // 오른쪽 위 대각선
        right_down(mat, row - 1, col - 1, go);        // 오른쪽 아래 대각선
    }

    for (int i = 0; i < 8; i++) {       // 바둑돌 개수
        for (int j = 0; j < 8; j++) {
            if (mat[i][j] == 'O') {
                white += 1;
            }
            else if (mat[i][j] == 'X') {
                black += 1;
            }
        }
    }
    cout << black << " " << white << endl;
    for (int i = 0; i < 8; i++) {       // 출력
        for (int j = 0; j < 8; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

void left(char** mat, int row, int col, char go) {
    int mcol = col - 1;
    while (mcol >= 0) {
        if (mat[row][mcol] == '+') {
            break;
        }
        if (mat[row][mcol] == go) {
            for (int i = mcol + 1; i < col; i++) {
                mat[row][i] = go;
            }
            break;
        }
        mcol--;
    }
}
void right(char* mat[], int row, int col, char go) {
    int mcol = col + 1;
    while (mcol < 8) {
        if (mat[row][mcol] == '+') {
            break;
        }
        if (mat[row][mcol] == go) {
            for (int i = col + 1; i < mcol; i++) {
                mat[row][i] = go;
            }
            break;
        }
        mcol++;
    }
}
void up(char* mat[], int row, int col, char go) {
    int mrow = row - 1;
    while (mrow >= 0) {
        if (mat[mrow][col] == '+') {
            break;
        }
        if (mat[mrow][col] == go) {
            for (int i = mrow + 1; i < row; i++) {
                mat[i][col] = go;
            }
            break;
        }
        mrow--;
    }
}
void down(char* mat[], int row, int col, char go) {
    int mrow = row + 1;
    while (mrow < 8) {
        if (mat[mrow][col] == '+') {
            break;
        }
        if (mat[mrow][col] == go) {
            for (int i = row + 1; i < mrow; i++) {
                mat[i][col] = go;
            }
            break;
        }
        mrow++;
    }
}
void left_up(char* mat[], int row, int col, char go) {
    int mrow = row - 1; int mcol = col - 1;
    while ((mrow >= 0) && (mcol >= 0)) {
        if (mat[mrow][mcol] == '+') {
            break;
        }
        if (mat[mrow][mcol] == go) {
            int index_col = mcol + 1;
            for (int i = mrow + 1; i < row; i++) {
                mat[i][index_col] = go;
                index_col++;
            }
            break;
        }
        mrow--; mcol--;
    }
}
void left_down(char* mat[], int row, int col, char go) {
    int mrow = row + 1; int mcol = col - 1;
    while ((mrow < 8) && (mcol >= 0)) {
        if (mat[mrow][mcol] == '+') {
            break;
        }
        if (mat[mrow][mcol] == go) {
            int index_col = col - 1;
            for (int i = row + 1; i < mrow; i++) {
                mat[i][index_col] = go;
                index_col--;
            }
            break;
        }
        mrow++; mcol--;
    }
}
void right_up(char* mat[], int row, int col, char go) {
    int mrow = row - 1; int mcol = col + 1;
    while ((mrow >= 0) && (mcol < 8)) {
        if (mat[mrow][mcol] == '+') {
            break;
        }
        if (mat[mrow][mcol] == go) {
            int index_col = mcol - 1;
            for (int i = mrow + 1; i < row; i++) {
                mat[i][index_col] = go;
                index_col--;
            }
            break;
        }
        mrow--; mcol++;
    }
}
void right_down(char* mat[], int row, int col, char go) {
    int mrow = row + 1; int mcol = col + 1;
    while ((mrow < 8) && (mcol < 8)) {
        if (mat[mrow][mcol] == '+') {
            break;
        }
        if (mat[mrow][mcol] == go) {
            int index_col = col + 1;
            for (int i = row + 1; i < mrow; i++) {
                mat[i][index_col] = go;
                index_col++;
            }
            break;
        }
        mrow++; mcol++;
    }
}
