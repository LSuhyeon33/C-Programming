#include <iostream>
using namespace std;

int main() {
    int numTestcase;
    cin >> numTestcase;

    for (int i = 0; i < numTestcase; i++) {
        int data;
        cin >> data;

        char** arr = new char* [data];  // �迭 ����
        for (int i = 0; i < data; i++) {
            arr[i] = new char[data];
        }
        for (int i = 0; i < data; i++) {  // �迭 ' . '���� �ʱ�ȭ
            for (int j = 0; j < data; j++) {
                arr[i][j] = '.';
            }
        }
        for (int i = 0; i < data; i++) {  // '-' ä���
            arr[0][i] = '-';
            arr[data / 2][i] = '-';
            arr[data - 1][i] = '-';
        }
        for (int i = 1; i < (data- 1); i++) {  // '|' ä���
            arr[i][0] = '|';
            arr[i][data / 2] = '|';
            arr[i][data - 1] = '|';
        }
        for (int i = 1; i < (data - 1); i++) {  // '\' ä���
            arr[i][i] = '\\';
        }
        for (int i = 1; i < (data - 1); i++) {  // '/' ä���
            arr[i][(data -1) -i] = '/';
        }
        for (int i = 0; i < 3; i++) {  // '+' ä���
            for (int j = 0; j < 3; j++) {
                arr[i * (data / 2)][j * (data / 2)] = '+';
            }
        }
        arr[data / 2][data / 2] = '*';  // '*' ä���

        for (int i = 0; i < data; i++) {  // �迭 ���
            for (int j = 0; j < data; j++) {
                cout << arr[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}