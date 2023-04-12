#include <iostream>
using namespace std;

int main() {
    int numTestcase;
    cin >> numTestcase;

    for (int i = 0; i < numTestcase; i++) {
        int data, re;

        cin >> data;
        re = data;

        int** arr = new int* [data];  //배열 선언
        for (int i = 0; i < data; i++) {
            arr[i] = new int[data];
        }
        for (int i = 0; i < data; i++) {  //배열 0으로 초기화
            for (int j = 0; j < data; j++) {
                arr[i][j] = 0;
            }
        }

        if ((data % 4) == 3) {
            for (int j = 0; j < ((re + 1) / 4); j++) {
                for (int i = (j * 2); i < (data - (j * 2)); i++) {  //위가로
                    arr[j * 2][i] = 1;
                }
                for (int i = ((j * 2) + 1); i < (data - ((j * 2) + 1)); i++) {  //왼쪽세로
                    arr[i][j * 2] = 1;
                }
                for (int i = ((j * 2) + 1); i < (data - ((j * 2) + 1)); i++) {  //오른쪽세로
                    arr[i][data - ((j * 2) + 1)] = 1;
                }
                for (int i = (j * 2); i < (data - (j * 2)); i++) {  //아래가로
                    arr[data - ((j * 2) + 1)][i] = 1;
                }
            }
        }
        else {
            for (int j = 0; j < ((re - 1) / 4); j++) {
                for (int i = ((j * 2) + 1); i < (data - ((j * 2) + 1)); i++) {  //위가로
                    arr[(j * 2) + 1][i] = 1;
                }
                for (int i = ((j + 1) * 2); i < (data - ((j + 1) * 2)); i++) {  //왼쪽세로
                    arr[i][(j * 2) + 1] = 1;
                }
                for (int i = ((j + 1) * 2); i < (data - ((j + 1) * 2)); i++) {  //오른쪽세로
                    arr[i][data - ((j + 1) * 2)] = 1;
                }
                for (int i = ((j * 2) + 1); i < (data - ((j * 2) + 1)); i++) {  //아래가로
                    arr[data - ((j + 1) * 2)][i] = 1;
                }
            }
        }

        for (int i = 0; i < data; i++) {
            for (int j = 0; j < data; j++) {
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}