// Problem: �־��� ������ �� ���ϱ�
// ���δ��б� ���б������ �������Ⱦ�ȣ���а� 3�г� 20202101 �̼���

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