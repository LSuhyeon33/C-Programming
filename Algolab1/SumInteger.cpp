// Problem: �־��� ������ �� ���ϱ�
// ���δ��б� ���б������ �������Ⱦ�ȣ���а� 3�г� 20202101 �̼���

#include <iostream>
using namespace std;

int main()
{
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int numData, data;
        int sum = 0;

        cin >> numData;

        if ((1 <= numData) && (numData <= 100)) {
            for (int j = 0; j < numData; j++) {
                cin >> data;
                sum += data;
            }
            cout << sum << endl;
        }
        else {
            cout << "Error: 1�̻� 100������ ������ �Է��Ͻÿ�.";
        }
    }

    return 0;
}