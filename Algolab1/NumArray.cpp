// Problem: �־��� ������ �� ���ϱ�
// ���δ��б� ���б������ �������Ⱦ�ȣ���а� 3�г� 20202101 �̼���

#include <iostream>
using namespace std;

void numArray(int a, int b, int c) {
    if (a <= b) {
        if (b <= c) cout << a << " " << b << " " << c << endl;
        else if (a <= c) cout << a << " " << c << " " << b << endl;
        else cout << c << " " << a << " " << b << endl;
    } else {
         if (a <= c) cout << b << " " << a << " " << c << endl;
         else if (b <= c)cout << b << " " << c << " " << a << endl;
         else cout << c << " " << b << " " << a << endl;
    }
}

int main()
{
    int numTestCase;

    cin >> numTestCase;

    for (int i = 0; i < numTestCase; i++) {
        int a, b, c;

        cin >> a >> b >> c;    
        numArray(a, b, c);
    }
    return 0;
}