#include <iostream>
using namespace std;

void input(int** arr, int size) {
    for (int i = 1; i < (size + 1); i++) {  
        for (int j = 1; j < (size + 1); j++) {
            arr[i - 1][j - 1] = (static_cast<unsigned long long>(i) - 1) * size + j;
        }
    }
}

int main() {
    int numTestcase;
    cin >> numTestcase;

    for (int i = 0; i < numTestcase; i++) {
        int size, a, b;
        int data = 0, x = 0, y = 0, sign = 1;
        cin >> size >> a >> b;  //size 값 입력

        int** arr = new int* [size];  //배열 선언
        for (int i = 0; i < size; i++) {
            arr[i] = new int[size];
        }
        input(arr, size);  //배열 값 넣기

        int* arr1 = new int[(size * size)];  //배열 선언

        for (int k = 0; k < size; k++) {
            arr1[data] = arr[y][x];
            data++; x += sign;
        }
        x -= 1;
        for (int i = (size - 1); i > 0; i--) {
            for (int j = 0; j < i; j++) {
                y += sign;
                arr1[data] = arr[y][x];
                data++;
            }
            sign *= -1;
            for (int k = 0; k < i; k++) {
                x += sign;
                arr1[data] = arr[y][x];
                data++;
            }
        }
        for (int i = (a - 1); i < b; i++) {  //배열 출력
            cout << arr1[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
