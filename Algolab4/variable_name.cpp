// Problem: �����̸�
// ���δ��б� ���б������ �������Ⱦ�ȣ���а� 3�г� 20202101 �̼���

#include <iostream>
using namespace std;

#define MAX     257     // �Է� string �ִ� ����

int main() {
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        char variable[MAX];
        bool result = true;
        int index = 0;

        cin >> variable;

        while (variable[index] != 0) {
            if (variable[0] >= '0' && variable[0] <= '9') {    // ù ���ڰ� ���ڸ� false
                result = false;
                break;
            }
            if ((variable[index] >= 'A' && variable[index] <= 'Z') || (variable[index] >= 'a' && variable[index] <= 'z') || (variable[index] >= '0' && variable[index] <= '9') || variable[index] == '_') {    // ���ڰ� ������, ����, '_'
                index++;
                continue;
            }
            else {
                result = false;
                break;
            }
        }
        (result == true) ? cout << "1" << endl : cout << "0" << endl;
    }
    return 0;
}

/*
#include <cctype>

int main() {
    int numTestCase;
   
    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        char variable[MAX];
        bool result = true;
        int index = 0;

        cin >> variable;

        while (variable[index] != 0) {
            if (isdigit(variable[0])) {    // ù ���ڰ� ���ڸ� false
                result = false;
                break;
            }
            if (isalnum(variable[index]) == 0) {    // ���ڰ� ������, ���ڰ� �ƴ�
                if (variable[index] != '_') {     // '_'�� �ƴ�
                    result = false;
                    break;
                }
            }
            index++;
        }
        (result == true) ? cout << "1" << endl : cout << "0" << endl;
    }
    return 0;
}
*/
