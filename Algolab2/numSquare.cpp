#include <iostream>
using namespace std;

int main() {
    int numTestcase;
    cin >> numTestcase;

    for (int i = 0; i < numTestcase; i++) {
        int data, re;

        cin >> data;
        re = data;

        int** arr = new int* [data];  //�迭 ����
        for (int i = 0; i < data; i++) {
            arr[i] = new int[data];
        }
        for (int i = 0; i < data; i++) {  //�迭 0���� �ʱ�ȭ
            for (int j = 0; j < data; j++) {
                arr[i][j] = 0;
            }
        }

        if ((data % 4) == 3) {
            for (int j = 0; j < ((re + 1) / 4); j++) {
                for (int i = (j * 2); i < (data - (j * 2)); i++) {  //������
                    arr[j * 2][i] = 1;
                }
                for (int i = ((j * 2) + 1); i < (data - ((j * 2) + 1)); i++) {  //���ʼ���
                    arr[i][j * 2] = 1;
                }
                for (int i = ((j * 2) + 1); i < (data - ((j * 2) + 1)); i++) {  //�����ʼ���
                    arr[i][data - ((j * 2) + 1)] = 1;
                }
                for (int i = (j * 2); i < (data - (j * 2)); i++) {  //�Ʒ�����
                    arr[data - ((j * 2) + 1)][i] = 1;
                }
            }
        }
        else {
            for (int j = 0; j < ((re - 1) / 4); j++) {
                for (int i = ((j * 2) + 1); i < (data - ((j * 2) + 1)); i++) {  //������
                    arr[(j * 2) + 1][i] = 1;
                }
                for (int i = ((j + 1) * 2); i < (data - ((j + 1) * 2)); i++) {  //���ʼ���
                    arr[i][(j * 2) + 1] = 1;
                }
                for (int i = ((j + 1) * 2); i < (data - ((j + 1) * 2)); i++) {  //�����ʼ���
                    arr[i][data - ((j + 1) * 2)] = 1;
                }
                for (int i = ((j * 2) + 1); i < (data - ((j * 2) + 1)); i++) {  //�Ʒ�����
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