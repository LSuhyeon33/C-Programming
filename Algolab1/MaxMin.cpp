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
        int Max, Min;

        cin >> numData;

        if ((1 <= numData) && (numData <= 100)) {

            cin >> data;
            Max = Min = data;    // �ʱⰪ ����

            for (int j = 1; j < numData; j++) {
                cin >> data;

                if (data > Max) Max = data;
                if (data < Min) Min = data;
            }
            cout << Max << " " << Min << endl;
        }
        else {
            cout << "Error: 1�̻� 100������ ������ �Է��Ͻÿ�.";
        }
    }
    return 0;
}